def genpalin(length):
    palindromes = []

    if length == 1:

        return list(range(1, 10))

    half_length = (length + 1) // 2  
    start = 10 ** (half_length - 1)
    end = 10 ** half_length          

    for base in range(start, end):
        s = str(base)
        if length % 2 == 0:

            palindrome = int(s + s[::-1])
        else:

            palindrome = int(s + s[-2::-1])
        palindromes.append(palindrome)

    return palindromes
def genpalin0(length):
    palindromes = []

    if length == 1:

        return [str(i) for i in range(10)]

    half_length = (length + 1) // 2  
    start = 0  
    end = 10 ** half_length          

    for base in range(start, end):
        s = f"{base:0{half_length}}"  
        if length % 2 == 0:

            palindrome = s + s[::-1]
        else:

            palindrome = s + s[-2::-1]
        palindromes.append(palindrome)

    return palindromes
import sys
n, m = map(int, sys.stdin.read().split())
from collections import defaultdict
cnt = defaultdict(int)
shift = '0' * (n // 2)
for i in genpalin0(n // 2):
    cur = str(i)
    cnt[int(cur) % m] += 1
ans = 0
for i in genpalin(n // 2):
    cur = int(str(i) + shift) % m
    #print(str(i) + shift)
    #print(cnt[(m - cur) % m])
    ans += cnt[(m - cur) % m];
print(ans)