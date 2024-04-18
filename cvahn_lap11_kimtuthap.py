inp = int(input())
i = 1
count = 1
while inp > i :
    inp -= i
    count += 1
    i += 2
if inp <= i:
    print(count-1)
else:
    print(count)
