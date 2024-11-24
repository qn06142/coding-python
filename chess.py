with open("covua.inp", "r") as f:
    A = int(f.readline())
    B = int(f.readline())
    K = int(f.readline())
out = []
if A > B:
    if B + K > A:
        out.append("YES")
    else:
        out.append("NO")
elif A < B:
    if A + K > B:
        out.append("YES")
    else:
        out.append("NO")
else:
    out.append("YES")
with open("covua.out", "w") as f:
    f.write(out[0])