#ifndef KS_STRING_UTILS_H
#define KS_STRING_UTILS_H



namespace ks {
    namespace string_utils {
        inline const char* hashcode_to_string(const unsigned int value)
        {
            static char out[11];
            out[0] = '0';
            out[1] = 'x';

            for(int i = 0; i < 8; i++) {
                const unsigned int nibble = (value >> ((7 - i) * 4)) & 0xF;
                out[2 + i] = (nibble < 10) ? ('0' + nibble) : ('A' + nibble - 10);
            }

            out[10] = '\0';
            return out;
        }
    }
}


#endif //KS_STRING_UTILS_H
