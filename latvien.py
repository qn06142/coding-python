f = [1, 2]
for i in range(0, 500):
    f.append(f[-1] + f[-2])
for i in range(0, int(input())):
    print(f[int(input())])
