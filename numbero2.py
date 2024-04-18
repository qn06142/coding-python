#files shenatigans
fileread=open("MM.INP","r")
filewrite=open("MM.OUT","w")
file=fileread.read()
#importing shiz
import string
#defining funcs
def strsplitter(string):
    list = []
    for i in range(0, len(string)):
        list.append(string[i:i+1])
    return list
def passcheckert2(list):
    strnumberos = 0
    struppercase = 0
    strlowercase = 0
    listnumberos = []
    listuppercase = []
    listlowercase = []
    for i in range(0, len(list)):
        if list[i] in numberos:
            if list[i] not in listnumberos:
                listnumberos.append(list[i])
                strnumberos = strnumberos + 1
        if list[i] in asciilowercase:
            if list[i] not in listlowercase:
                listlowercase.append(list[i])
                strlowercase = strlowercase + 1
        if list[i] in asciiuppercase:
            if list[i] not in listuppercase:
                listuppercase.append(list[i])
                struppercase = struppercase + 1
    if len(list) >= 6 and strnumberos >=2 and struppercase >= 2 and strlowercase >= 2:
        return True
    else:
        return False

def passcheckert1(list):
    strnumberos = 0
    struppercase = 0
    strlowercase = 0
    listnumberos = []
    listuppercase = []
    listlowercase = []
    for i in range(0, len(list)):
        if list[i] in numberos:
            strnumberos = strnumberos + 1
        if list[i] in asciilowercase:
            strlowercase = strlowercase + 1
        if list[i] in asciiuppercase:
            struppercase = struppercase + 1
    if len(list) >= 6 and strnumberos >=1 and struppercase >= 1 and strlowercase >= 1:
        return True
    else:
        return False
#defining vars
asciilowercase = strsplitter(string.ascii_lowercase)
asciiuppercase = strsplitter(string.ascii_uppercase)
numberos = strsplitter(string.digits)
print(asciilowercase, asciiuppercase, numberos)
string = str(file)
print(string)
list = []
strnumberos = 0
struppercase = 0
strlowercase = 0
listnumberos = []
listuppercase = []
listlowercase = []
fileline1 = ""
fileline2 = ""
possiblecomblistraw = []
possiblecomblist = []
listgoodpasst1 = []
listlengoodpasst1 = []
listgoodpasst2 = []
listlengoodpasst2 = ["0"]
minlent1 = 0
#splitting string
list = strsplitter(string)
print(list)
#counting.exe
for i in range(0, len(list)):
    if list[i] in numberos:
        if list[i] not in listnumberos:
            listnumberos.append(list[i])
            strnumberos = strnumberos + 1
    if list[i] in asciilowercase:
        if list[i] not in listlowercase:
            listlowercase.append(list[i])
            strlowercase = strlowercase + 1
    if list[i] in asciiuppercase:
        if list[i] not in listuppercase:
            listuppercase.append(list[i])
            struppercase = struppercase + 1
#printing 3a
print(struppercase)
print(strlowercase)
print(strnumberos)
fileline1 = struppercase + strlowercase + strnumberos
#checkingifpasswordtype1.exe and checkingifpasswordtype2.exe
#step1: making a list of all possible str combinations
for i in range(0, len(string)):
    for j in range(0, len(string)):
        possiblecomblistraw.append(string[i:j])
print(possiblecomblistraw)
for i in range(0, len(possiblecomblistraw)):
    if possiblecomblistraw[i] is not "":
        possiblecomblist.append(possiblecomblistraw[i])
print(possiblecomblist)
for i in range(0, len(possiblecomblist)):
    if passcheckert1(possiblecomblist[i]) == True:
        #should've just len()ed it but hey, why not?
        listgoodpasst1.append(possiblecomblist[i])
    if passcheckert2(possiblecomblist[i]) == True:
        #should've just len()ed it but hey, why not?
        listgoodpasst2.append(possiblecomblist[i])
print(listgoodpasst1)
#making list of lens
for i in range(0, len(listgoodpasst1)):
        listlengoodpasst1.append(len(listgoodpasst1[i]))
for i in range(0, len(listgoodpasst2)):
        listlengoodpasst2.append(len(listgoodpasst2[i]))
#printing shit
print(listlengoodpasst1)
print(min(listlengoodpasst1))
print(listlengoodpasst2)
print(min(listlengoodpasst2))
#writeing file
fileline1 = str(struppercase) + " " + str(strlowercase) + " " + str(strnumberos)
fileline2 = str(min(listlengoodpasst1)) + " " + str(min(listlengoodpasst2))
filewrite.write(fileline1 + "\n" + fileline2)
filewrite.close()
