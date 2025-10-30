mapping = {
    "Rock" : 1,
    "Scissors" : 2,
    "Paper" : 3
}

losing = {
    2 : 1,
    3 : 2,
    1 : 3
}
winning = {
    1 : 2,
    2 : 3,
    3 : 1
}

a, b = (mapping[i] for i in input().split())

if b == losing[a]:
    print("Player 2")
if b == winning[a]:
    print("Player 1")
if a == b:
    print("Draw")