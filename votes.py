with open("vote.inp", 'r') as f:
	size = int(f.readline().strip())
	ppls = tuple(tuple(1 if i == 'X' else 0 for i in f.readline().split()) for i in range(0, size))
votes = list([index] + list(i) for index, i in enumerate(zip(*ppls)))
for index, item in enumerate(votes):
	votes[index] = [item[0], sum(item[1:])]
votes.sort(key= lambda votes: votes[-1])
maxes = []
maxvotes = max(i[-1] for i in votes)
for i in reversed(votes):
	if i[-1] == maxvotes:
		maxes.append(i)
	else:
		break
maxes.reverse()
with open("vote.out", "w") as f:
	f.write(str(len(maxes)) + " " + str(maxvotes))
	f.write("\n" + ' '.join(map(str, (i[0]+1  for i in maxes))))