tmap = dict()
times = []

for _ in range(int(input())):
	start, end = input().split()
	start = int(start)
	end = int(end)

	tmap[start] = 1
	tmap[end] = -1
	times.append(start)
	times.append(end)

times.sort()

curr_ppl = 0
max_ppl = 0

for t in times:
	curr_ppl += tmap[t]
	max_ppl = max(max_ppl, curr_ppl)

print(max_ppl)