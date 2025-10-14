def gba_lz77_decompress(data: bytes) -> bytes:
    """
    Decompresses a GBA-style LZ77 compressed byte stream (type 0x10).
    Returns the decompressed bytes.
    """

    if len(data) < 4:
        raise ValueError("Data too short to contain LZ77 header")

    if data[0] != 0x10:
        raise ValueError("Not a valid GBA LZ77 stream (missing 0x10 header)")

    decompressed_size = data[1] | (data[2] << 8) | (data[3] << 16)
    src_off = 4
    dst = bytearray()

    while len(dst) < decompressed_size:
        if src_off >= len(data):
            raise ValueError("Unexpected end of compressed data")

        # Read control byte — 8 blocks (bits)
        flags = data[src_off]
        src_off += 1

        for i in range(8):
            if len(dst) >= decompressed_size:
                break

            if (flags & (0x80 >> i)) == 0:
                # Uncompressed byte
                if src_off >= len(data):
                    raise ValueError("Unexpected end of data while reading literal")
                dst.append(data[src_off])
                src_off += 1
            else:
                # Compressed block (2 bytes)
                if src_off + 1 >= len(data):
                    raise ValueError("Unexpected end of data while reading compressed block")

                first = data[src_off]
                second = data[src_off + 1]
                src_off += 2

                # Length = upper nibble of first + 3
                # Distance = lower nibble of first << 8 + second + 1
                length = ((first >> 4) & 0xF) + 3
                distance = ((first & 0xF) << 8) + second + 1

                # Copy 'length' bytes from 'distance' bytes behind
                for _ in range(length):
                    if distance > len(dst):
                        raise ValueError("Invalid backreference (distance too large)")
                    dst.append(dst[-distance])

    # Truncate to declared decompressed size (in case of padding)
    return bytes(dst[:decompressed_size])
