bitches = [int(i) for i in input().split()]
mod = bitches.pop(-1)
bitches.sort()
print(max(bitches[0]*bitches[1], bitches[-1]*bitches[-2])%mod)