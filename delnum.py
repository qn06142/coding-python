#vars
string = "1548994991"
possiblecomblistraw = []
possiblecomblist = []
for i in range(0, len(string)):
    for j in range(0, len(string)):
        possiblecomblistraw.append(string[i:j])
print(possiblecomblistraw)
for i in range(0, len(possiblecomblistraw)):
    if possiblecomblistraw[i] is not "":
        possiblecomblist.append(possiblecomblistraw[i])
