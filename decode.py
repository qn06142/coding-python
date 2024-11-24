def decode(msg):
    abc = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    res = ''
    for i in range(0, len(msg), 2):
        char = msg[i]
        num = int(msg[i+1])
        new_pos = (abc.index(char) + num) % 26
        res += abc[new_pos]
    return res

msg = input()
print(decode(msg))