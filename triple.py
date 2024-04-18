import sys
sys.set_int_max_str_digits(10**6)
with open("triple.inp", "r") as f:
	testcases = [[int(i) for i in f.readline().split()] for i in range(0, int(f.readline()))]
def solve(n, k):
    n = list(map(int, str(n)))
    for _ in range(k):
        n = [i*3 for i in n]
        n = list(map(int, str(int(''.join(map(str, n))))))
    return int(''.join(map(str, n))) % 123456789
with open("triple.out", "w") as f:
	for i in testcases:
		f.write(str(solve(*i)) + "\n")