n, x = tuple(int(i) for i in input().split())
operations = tuple(tuple(int(i) for i in input().split()) for i in range(0, x))
def shuffle_cards(n, x, operations):
    cards = list(range(1, n+1))
    for operation in operations:
        i, m, j = operation
        i -= 1
        j -= 1
        segment = cards[i:i+m]
        del cards[i:i+m]
        cards[j:j] = segment
    return cards

print(' '.join(map(str, shuffle_cards(n, x, operations))))