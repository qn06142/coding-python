k = int(input())
s = input()
print(sorted([(s+s)[i:i+len(s)] for i in range(0, len(s))])[k-1] if k < len(s) else -1)