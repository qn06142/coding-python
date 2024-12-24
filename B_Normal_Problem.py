
for _ in range(int(input())):
    s = ''.join(reversed(input()))
    for i in s:
        if i == 'p':
            print('q', end='')
        elif i == 'q':
            print('p', end='')
        else:
            print('w', end='')
    print()