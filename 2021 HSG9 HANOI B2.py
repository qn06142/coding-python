size = int(input().strip())
ppls = tuple(tuple(1 if i == 'X' else 0 for i in input().split()) for i in range(0, size))
votes = list((index,sum(i)) for index, i in enumerate(zip(*ppls)))

max_votes = 0
winners = []
for i, count in votes:
    if count > max_votes:
        max_votes = count
        winners = [i + 1]
    elif count == max_votes:
        winners.append(i + 1)

print(len(winners), max_votes)
for winner in winners:
    print(winner, end=" ")
