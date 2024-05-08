def decode_message(message):
    decoded_message = ""
    for char in message:
        ascii_val = ord(char)
        if 33 <= ascii_val <= 126:
            reversed_bits = '{0:08b}'.format(ascii_val)[::-1]
            new_ascii_val = int(reversed_bits, 2)
            if 33 <= new_ascii_val <= 126:
                decoded_message += chr(new_ascii_val)
            else:
                decoded_message += char
        else:
            decoded_message += char
    return decoded_message

with open('CAU3.INP', 'r') as file:
    encoded_messages = file.readlines()

with open('CAU3.OUT', 'w') as file:
    for message in encoded_messages:
        decoded_message = decode_message(message.strip())
        file.write(decoded_message + '\n')
