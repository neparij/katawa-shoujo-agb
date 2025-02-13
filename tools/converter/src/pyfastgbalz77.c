#define PY_SSIZE_T_CLEAN
#include <Python.h>

#undef min
#undef max
inline int min(int a, int b) {
  return a < b ? a : b;
}
inline int max(int a, int b) {
  return a > b ? a : b;
}

#define LZ77_MAGIC_BYTE 0x10
#define LZ77_MAX_SUPPORTED_SIZE 0xFFFFFF

static PyObject* pyfastgbalz77_SizeTooLargeError;

void pyfastgbalz77_get_match_length_and_distance(char* new_data, int new_length, char* old_data, int old_length, int min_distance, int* length, int* distance) {
  *length = 0; // The length of the match
  *distance = 0; // The distance backwards to the start of the match
  
  if (new_length == 0) {
    return;
  }
  
  // Try every possible offset in the already compressed data.
  int max_start_to_check = old_length - min_distance;
  for (int i = 0; i < max_start_to_check; i++) {
    int current_old_start = i;
    
    // Figure out how many bytes can be copied at this offset.
    int current_copyable_length = 0;
    for (int j = 0; j < new_length; j++) {
      if (old_data[current_old_start + j] != new_data[j]) {
        break; 
      }
      current_copyable_length++;
    }
    
    if (current_copyable_length > *length) {
      *length = current_copyable_length;
      *distance = old_length - i;
      
      if (*length == new_length) {
        break;
      }
    }
  }
}

static PyObject* pyfastgbalz77_compress(PyObject* self, PyObject* args) {
  PyObject* src_bytes;
  int for_16_bit;
  char* src;
  
  if (!PyArg_ParseTuple(args, "Sp", &src_bytes, &for_16_bit)) {
    return NULL; // Error already raised
  }
  
  src = PyBytes_AsString(src_bytes);
  if (!src) {
    return NULL; // Error already raised
  }
  
  int src_size = (int)PyBytes_Size(src_bytes);
  if (src_size > LZ77_MAX_SUPPORTED_SIZE) {
    PyErr_SetString(pyfastgbalz77_SizeTooLargeError, "Data larger than 0xFFFFFF bytes cannot be LZ77 compressed.");
    return NULL;
  }
  
  int min_distance = 0;
  if (for_16_bit) {
    // The GBA's 16 bit LZ77 decompression function requires the distance to be at least 1 byte backwards instead of 0 bytes.
    min_distance = 1;
  }
  
  char* dst;
  // It's theoretically possible for the compressed data to be larger than the uncompressed data (though this is unlikely unless the data is just completely random bytes).
  // The max size the compressed data can be is a bit over 12.5% more than the uncompressed data, but we use twice the uncompressed size as the buffer size to be safe and simplify things a bit.
  int max_possible_comp_size = src_size*2;
  dst = malloc(max_possible_comp_size);
  if(!dst) {
    return PyErr_NoMemory();
  }
  int src_off = 0;
  int dst_off = 0;
  
  dst[dst_off++] = LZ77_MAGIC_BYTE;
  dst[dst_off++] = (src_size & 0x0000FF);
  dst[dst_off++] = (src_size & 0x00FF00) >> 8;
  dst[dst_off++] = (src_size & 0xFF0000) >> 16;
  
  int buffered_blocks = 0;
  char* curr_block_control = &dst[dst_off++];
  *curr_block_control = 0;
  while (src_off < src_size) {
    if (buffered_blocks == 8) {
      //　We've got all 8 blocks the current block control can support, so add a new block control.
      curr_block_control = &dst[dst_off++];
      *curr_block_control = 0;
      buffered_blocks = 0;
    }
    
    int old_length, match_length, match_distance;
    
    old_length = min(src_off, 0x1000); // Distance-1 is stored as 12 bits
    pyfastgbalz77_get_match_length_and_distance(
      &src[src_off],
      min(src_size-src_off, 0x12),
      &src[src_off-old_length],
      old_length,
      min_distance,
      &match_length, &match_distance
    );
    
    if (match_length < 3) {
      // If length is less than 3 it should be uncompressed data.
      // Just copy a single byte.
      dst[dst_off++] = src[src_off++];
    } else {
      src_off += match_length;
      
      // Set the compressed flag bit for this block.
      *curr_block_control |= (1 << (7-buffered_blocks));
      
      dst[dst_off]    = (((match_distance-1) >> 8) & 0x0F); // Bits 0xF00 of the distance
      dst[dst_off++] |= (((match_length  -3) << 4) & 0xF0); // Number of bytes to copy
      dst[dst_off++]  = ( (match_distance-1)       & 0xFF); // Bits 0x0FF of the distance
    }
    
    buffered_blocks++;
  }
  
  int dst_size = dst_off;
  PyObject* dst_bytes = PyBytes_FromStringAndSize(dst, dst_size);
  free(dst);
  return dst_bytes;
}

static PyMethodDef pyfastgbalz77Methods[] = {
  {"compress", pyfastgbalz77_compress, METH_VARARGS, "Takes data as a bytes object and returns the data LZ77 compressed as another bytes object."},
  {NULL, NULL, 0, NULL} // Sentinel
};

static struct PyModuleDef pyfastgbalz77_module = {
  PyModuleDef_HEAD_INIT,
  "pyfastgbalz77", // Module name
  NULL, // Documentation
  -1, // Size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
  pyfastgbalz77Methods
};

PyMODINIT_FUNC PyInit_pyfastgbalz77(void) {
  PyObject* module;
  
  module = PyModule_Create(&pyfastgbalz77_module);
  if (module == NULL) {
    return NULL;
  }
  
  pyfastgbalz77_SizeTooLargeError = PyErr_NewException("pyfastgbalz77.SizeTooLargeError", NULL, NULL);
  Py_XINCREF(pyfastgbalz77_SizeTooLargeError);
  if (PyModule_AddObject(module, "SizeTooLargeError", pyfastgbalz77_SizeTooLargeError) < 0) {
    Py_XDECREF(pyfastgbalz77_SizeTooLargeError);
    Py_CLEAR(pyfastgbalz77_SizeTooLargeError);
    Py_DECREF(module);
    return NULL;
  }
  
  return module;
}
