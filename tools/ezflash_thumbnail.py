import sys
import struct
import os

WIDTH = 120
HEIGHT = 80
EXPECTED_SIZE = 19256


def main():
    if len(sys.argv) != 3:
        print("Usage: python ezflash_thumbnail.py <input.bmp> <output.bmp>")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = sys.argv[2]

    try:
        with open(input_path, 'rb') as f:
            file_header = f.read(14)
            dib_header = f.read(40)

            width = struct.unpack('<I', dib_header[4:8])[0]
            height = struct.unpack('<i', dib_header[8:12])[0]
            bpp = struct.unpack('<H', dib_header[14:16])[0]

            if bpp != 24:
                raise ValueError(f"Expected 24-bit BMP, got {bpp}-bit")

            if width != WIDTH or abs(height) != HEIGHT:
                raise ValueError(f"Expected {WIDTH}x{HEIGHT} image, got {width}x{abs(height)}")

            # Calculate row size with padding
            row_size = ((width * 3 + 3) // 4) * 4
            pixel_data = f.read(row_size * abs(height))

        rgb555_data = bytearray()

        # Flip row order: read from bottom to top (bottom-up to top-down conversion)
        for y in range(HEIGHT - 1, -1, -1):
            row_start = y * row_size
            for x in range(WIDTH):
                pixel_offset = row_start + x * 3

                b = pixel_data[pixel_offset]
                g = pixel_data[pixel_offset + 1]
                r = pixel_data[pixel_offset + 2]

                # Convert to BGR555 (5-5-5 format)
                r5 = (b >> 3) & 0x1F
                g5 = (g >> 3) & 0x1F
                b5 = (r >> 3) & 0x1F

                rgb555 = (r5 << 10) | (g5 << 5) | b5
                rgb555_data.extend(struct.pack('<H', rgb555))

        # Add 2 bytes padding
        rgb555_data.extend(bytearray(2))
        file_size = 54 + len(rgb555_data)

        with open(output_path, 'wb') as f:
            # File header
            f.write(struct.pack('<2sI2HI', b'BM', file_size, 0, 0, 54))

            # DIB header
            f.write(struct.pack('<IIiHHIIIIII',
                                40,
                                WIDTH,
                                -HEIGHT,
                                1,    # Planes
                                16,   # Bits per pixel
                                0,    # Compression
                                len(rgb555_data),
                                2834, # X pixels per meter
                                2834, # Y pixels per meter
                                0,    # Colors in palette
                                0))   # Important colors

            # Pixel data
            f.write(rgb555_data)

        actual_size = os.path.getsize(output_path)
        if actual_size == EXPECTED_SIZE:
            print(f"✅ Successfully created {output_path} ({actual_size} bytes)")
        else:
            print(f"❌ Error: Expected file size {EXPECTED_SIZE} bytes, got {actual_size} bytes")
            sys.exit(1)

    except Exception as e:
        print(f"❌ Error: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()
