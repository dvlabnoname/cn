POLY = "1101"

def xor(a, b):
    return ''.join('0' if x == y else '1' for x, y in zip(a, b))

def compute_crc(data):
    for i in range(len(data) - len(POLY) + 1):
        if data[i] == '1':
            data = data[:i] + xor(data[i:i+len(POLY)], POLY) + data[i+len(POLY):]
    return data[-(len(POLY)-1):]

data = input("Enter data bits (max 45): ")
#if len(data) > 45: exit("Data too long!")

crc = compute_crc(data + '0' * (len(POLY) - 1))
print(f"CRC: {crc}\nTransmitted frame: {data + crc}")

received = input("Enter received frame: ")
print("Error detected." if '1' in compute_crc(received) else "No error detected.")
