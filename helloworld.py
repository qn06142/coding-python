import random as rand

letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', ';',
    ':', '!', '?', '-', '_', '(', ')', '[', ']', '{', '}', '"', "'",
    ' ']

a1 = ''
a2 = ''
a3 = ''
a4 = ''
a5 = ''
a6 = ''
a7 = ''
a8 = ''
a9 = ''
a10 = ''
a11 = ''
a12 = ''
from time import sleep
def print_(string):
    print(string, end = '\r')
    sleep(0.1)
while a1 != 'H':
    n = rand.randint(0, 78)
    a1 = letters[n]
    print_(a1)
while a2 != 'e':
    n = rand.randint(0, 78)
    a2 = letters[n]
    print_(a1 + a2)
while a3 != 'l':
    n = rand.randint(0, 78)
    a3 = letters[n]
    print_(a1 + a2 + a3)
while a4 != 'l':
    n = rand.randint(0, 78)
    a4 = letters[n]
    print_(a1 + a2 + a3 + a4)
while a5 != 'o':
    n = rand.randint(0, 78)
    a5 = letters[n]
    print_(a1 + a2 + a3 + a4 + a5)
while a6 != ' ':
    n = rand.randint(0, 78)
    a6 = letters[n]
    print_(a1 + a2 + a3 + a4 + a5 + a6)
while a7 != 'W':
    n = rand.randint(0, 78)
    a7 = letters[n]
    print_(a1 + a2 + a3 + a4 + a5 + a6 + a7)
while a8 != 'o':
    n = rand.randint(0, 78)
    a8 = letters[n]
    print_(a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8)
while a9 != 'r':
    n = rand.randint(0, 78)
    a9 = letters[n]
    print_(a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9)
while a10 != 'l':
    n = rand.randint(0, 78)
    a10 = letters[n]
    print_(a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9+ a10)
while a11 != 'd':
    n = rand.randint(0, 78)
    a11 = letters[n]
    print_(a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9+ a10 + a11)
while a12 != '!':
    n = rand.randint(0, 78)
    a12 = letters[n]
    print_(a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9+ a10 + a11 + a12)
print(a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9+ a10 + a11 + a12)