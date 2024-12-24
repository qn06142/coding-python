def count_handshakes(n, directions):
    right = 0
    handshakes = 0
    for i in range(n):
        if directions[i] == '>':
            right += 1
        elif directions[i] == '<':
            handshakes += right
    return handshakes
print(count_handshakes(int(input()), input()))
