inp = input().lower()
vowels = ("a", "o", "y", "e", "u", "i")
out = ""
for i in inp:
	if i not in vowels:
		out += '.' + i
print(out)