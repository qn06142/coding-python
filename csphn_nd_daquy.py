compressed1 = [input().split()]
compressed2 = [input().split()]

def decomp(compressed):
    out = ''
    for i in range(0, int(compressed.pop(0))):
        m = int(compressed.pop(0))
        x = compressed.pop(0)
        k = int(compressed.pop(0))
        out += x * k
    return out
print(decomp(compressed1))