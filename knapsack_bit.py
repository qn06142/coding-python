n = int(input().strip())
a = list(map(int, input().split()))

dp = 1  
for x in a:
    dp |= dp << x

print(dp.bit_count())