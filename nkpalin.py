# Python program

def longestPalSubstr(st):
    n = len(st)
    f = [[0 for x in range(n)] for y in range(n)]
    for i in range(n-1, -1, -1):
        f[i][i] = 1
        for j in range(i+1, n):
            f[i][j] = max(f[i+1][j], f[i][j-1])
            if st[i] == st[j]:
                f[i][j] = max(f[i][j], f[i+1][j-1] + 2)

    def printPal(i, j):
        if i > j:
            return
        if i == j:
            print(st[i], end="")
            return
        if st[i] == st[j] and f[i][j] == f[i+1][j-1] + 2:
            print(st[i], end="")
            printPal(i+1, j-1)
            print(st[j], end="")
        elif f[i][j] == f[i+1][j]:
            printPal(i+1, j)
        else:
            printPal(i, j-1)

    printPal(0, n-1)
    print()

# Driver code
if __name__ == '__main__':
    st = input()
    longestPalSubstr(st)
