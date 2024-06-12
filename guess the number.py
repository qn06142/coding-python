def query(mid):
    print(mid, flush=True)
    return input()

l = 1
r = int(1e6)
while l <= r:
    mid = (l + r) // 2
    if query(mid) == "<":
        r = mid - 1
    else:
        l = mid + 1

print("! " + str((l + r) // 2), flush=True)
