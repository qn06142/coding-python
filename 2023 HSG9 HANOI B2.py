inp = input().lower()
from string import ascii_lowercase as lowercase
for i in lowercase:
    inp = inp.replace(i, ' ')
inp = set(int(i) for i in inp.split())
print(len(inp))