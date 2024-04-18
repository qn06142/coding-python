#imports and funcs
from math import sqrt
from math import floor
from math import ceil
def primechecker(n):
    flag = False
    for i in range(2, ceil(sqrt(n))+1):
        if n%i == 0:
            flag = True
            return False
    return True
#vars
inp = int(input())
list1 = [2]
list3 = []
list4 = []
#making odd list(with 2)
for i in range(3, inp+1,2):
    list1.append(i)
#making list to check the big bois
tempchecklist = set(list1)
if floor(sqrt(inp)) in tempchecklist:
    list2 = list1[:list1.index(floor(sqrt(inp)))+1]
if floor(sqrt(inp))+1 in tempchecklist:
    list2 = list1[:list1.index(floor(sqrt(inp))+1)+1]
for i in range(0, len(list2)):
    if primechecker(list2[i]):
        list3.append(list2[i])
#checking
for i in range(0, len(list1)):
    flag = False
    for j in list3:
        if list1[i]%j == 0:
            flag = True
    if not flag:
        list4.append(list1[i])
for i in list4[:-1]:
    print(i)
