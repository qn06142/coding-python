n, k, m = tuple(int(i) for i in input().split())
heights = tuple(int(i) for i in input().split())
pps = []
#id: [isout, times called, height, index]
for i in enumerate(heights):
	pps.append([False, 0, i])
i = -1
while i < m-1:
	i += 1
	currpos = i%n
	currelem = pps[currpos]
	if currelem[0]:
		currpos += 1
		currelem = pps[currpos]
	if currelem[2][1] <= k:
		currelem[0] = True
		currelem[1] += 1
	else:
		currelem[1] += 1
	pps[currpos] = currelem
pps = sorted(pps, key = lambda x: x[-1][0])
for p in pps:
	print(p[1], end = ' ')
