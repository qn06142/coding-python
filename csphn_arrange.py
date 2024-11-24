from collections import defaultdict

def min_card_values(n, cards):
    card_groups = defaultdict(lambda: float('inf'))

    for card in cards:
        value, color = card
        card_groups[color] = min(card_groups[color], value)

    sorted_groups = sorted(card_groups.items())
    min_values = [value for color, value in sorted_groups]

    return len(sorted_groups), min_values

n = int(input())
cards = tuple(tuple(int(i) for i in input().split()) for i in range(0, n))

k, min_values = min_card_values(n, cards)

print(k)
print(*min_values)
