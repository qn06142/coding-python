#vars
inp = input().split()
inp = [int(i) for i in inp]
inp1 = [input().split() for i in range(0, int(inp[1]))]
inp1 = [[int(j) for j in i] for i in inp1]
deck = []
#list.init
deck = [i for i in range(1, inp[0]+1)]
#shuffling
def shuffle(deck, card, pos):
    deck.remove(card)
    pos = deck.index(pos)  # Find the position of the card with the integer 𝑗
    deck.insert(pos, card)  # Insert the card 𝑖 at that position
    return deck
for i in inp1:
    deck = shuffle(deck, i[0], i[1])
print(deck)
