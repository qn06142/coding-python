def compute_factorials(n):
    factorials = [1] * (n + 1)
    for i in range(2, n + 1):
        factorials[i] = factorials[i - 1] * i
    return factorials

def kth_permutation(n, k):
    factorials = compute_factorials(n)
    available = list(range(1, n + 1))
    permutation = []

    k -= 1  
    for i in range(n):
        base = factorials[n - 1 - i]
        index = k // base
        if index >= available.__len__():
            from sys import exit
            print(-1)
            exit();
        permutation.append(available[index])
        available.pop(index)
        k %= base

    return permutation

def permutation_to_number(perm):
    n = len(perm)
    factorials = compute_factorials(n)
    used = [False] * (n + 1)
    number = 0

    for i in range(n):
        smaller = 0
        for j in range(1, perm[i]):
            if not used[j]:
                smaller += 1
        number += smaller * factorials[n - 1 - i]
        used[perm[i]] = True

    return number + 1  

if __name__ == "__main__":
    n, k = tuple(int(i) for i in input().split())
    before = list(map(int, input().split()))
    permutation = kth_permutation(n, permutation_to_number(before) + k)
    print(" ".join(map(str, permutation)))

