input()
print(*(abs(i[0] - i[1]) for i in zip((int(i) for i in input().split()), (int(i) for i in input().split()))))