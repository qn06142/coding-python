#input
inputl1 = input()
inputl2 = input()
#defining vars
list = []
list1 = []
list2 = []
possiblecomblistraw = []
possiblecomblist = []
#defining funcs
def strsplitter(string):
    list = []
    for i in range(0, len(string)):
        list.append(string[i:i+1])
    return list
def strbruteforce(string):
    possiblecomblist = []
    possiblecomblistraw = []
    for i in range(0, len(string)):
        for j in range(0, len(string)):
            possiblecomblistraw.append(string[i:j])
    for i in range(0, len(possiblecomblistraw)):
        if not not possiblecomblistraw[i]:
            possiblecomblist.append(possiblecomblistraw[i])
    return possiblecomblist
#doing shit
list = strbruteforce(inputl1)
for i in range(0, len(list)):
    list1 = strbruteforce(list[i])
    print(list1)
    if not not list1:
        if all(item in list1 for item in list2):
            list2.append(list1)
