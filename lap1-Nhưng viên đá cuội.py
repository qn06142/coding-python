inp = int(input())
n = inp
out=[]
for i in range(1,n+1):
    if(n%i==0):
        out.append(i)
out1 = []
for i in out:
    out1.append(i*2+(n/i)*2)
print(int(min(out1)))
