n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort(reverse=True)
sum=a[0]
j=0
for i in range(1,len(a)):
    if a[i]+k<=a[j]:
        j += 1
    else:
        sum=sum+a[i]
print(sum)