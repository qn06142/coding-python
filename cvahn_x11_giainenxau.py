with open("giainenxau.inp", "r") as f:
    string = f.read().strip()

ans = ''
from string import digits
digits = set(digits)

numberos = []
compressedletters = []
temp = ''
for char in string:
    if char in digits:
        temp += char
    else:
        if temp != '':
            numberos.append(int(temp))
            temp = ''
        compressedletters.append(char)

string = ''
for i in range(len(numberos)):
    string += compressedletters[i] * numberos[i]

with open("Giainenxau.out", "w") as f:
    f.write(string)
