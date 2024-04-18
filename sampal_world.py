s1 = input()
s2 = input()
movesdict = {'ROCK': ('SCISSORS', "SLAP"), 'PAPER': ('ROCK', "SLAP"), 'SCISSORS': ('PAPER', "SLAP"), 'GUN': ('ROCK', 'PAPER', 'SCISSORS'), 'SLAP': ('GUN')}
if s1 == s2:
    print("TIE")
else:
    moves1 = movesdict[s1]
    if s2 in moves1:
        print("PLATYPUS")
    else:
        print("OOF")