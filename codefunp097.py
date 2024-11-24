def maxnumber(n, k):
    ans = 0
    for i in range(0, k):
        i = 1
        while n // i > 0:
            temp = (n//(i * 10))*i + (n % i)
            i *= 10
            if temp > ans:
                ans = temp
        n = ans	 

    return ans

k = int(input())
n = int(input())
print(maxnumber(n, k))