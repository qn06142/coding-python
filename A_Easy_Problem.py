for _ in range(int(input())):
    cnt = 0
    n = int(input())
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if(i + j == n): 
                cnt += 1
    print(cnt)