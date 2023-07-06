def barretts_reduction(a, b, m):
    # Convert hexadecimal values to integers
    a = int(a, 16)
    b = int(b, 16)
    m = int(m, 16)

    # Perform multiplication
    product = a * b

    # Barrett's reduction
    q = product >> 8  # 8-bit right shift
    r = product - q * m

    # Apply reduction again if necessary
    while r >= m:
        r -= m

    # Convert result back to hexadecimal
    result = hex(r)[2:].upper()

    # Pad result with leading zeros if necessary
    result = result.zfill(2)

    return result


# Example usage
a = "FF"  # Hexadecimal representation of unsigned char
b = "A5"  # Hexadecimal representation of unsigned char
m = "D3"  # Hexadecimal modulus

result = barretts_reduction(a, b, m)
print("Result:", result)


# Example usage
a = "FF"  # Hexadecimal representation of unsigned char
b = "A5"  # Hexadecimal representation of unsigned char
m = "D3"  # Hexadecimal modulus

result = barretts_reduction(a, b, m)
print("Result:", result)
