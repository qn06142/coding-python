MOD = 1000000007

mapping = {
    '0': {'0'},
    '1': {'1'},
    '2': {'2'},
    '3': {'3'},
    '4': {'4'},
    '5': {'5'},
    '6': {'6'},
    '7': {'7'},
    '8': {'8'},
    '9': {'9'},
    'a': {'0', '1', '2', '3'},
    'b': {'1', '2', '3', '4'},
    'c': {'2', '3', '4', '5'},
    'd': {'3', '4', '5', '6'},
    'e': {'4', '5', '6', '7'},
    'f': {'5', '6', '7', '8'},
    'g': {'6', '7', '8', '9'},
    '?': {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
}

t = int(input().strip())
for _ in range(t):
    P1 = input().strip()
    P2 = input().strip()

    total = 1
    for ch1, ch2 in zip(P1, P2):

        allowed1 = mapping[ch1]
        allowed2 = mapping[ch2]

        inter = allowed1.intersection(allowed2)
        count = len(inter)
        total = (total * count) % MOD

    print(total)