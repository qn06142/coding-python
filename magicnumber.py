from string import ascii_lowercase, digits

s = input().lower()
cnt = dict()
for i in digits:
    cnt[i] = 0
tot = 0
nums = []
for i in s:
    if not i.isdigit(): continue
    cnt[i] += 1
    tot += 1
print(tot)
print(*(cnt[i] for i in digits))

s = ''.join((i if i.isdigit() else ' ') for i in s)
nums = s.split()
print(sum(int(i) if ((int(i)) % 5 == 1 and int(i) % 2 == 0) else 0 for i in nums))