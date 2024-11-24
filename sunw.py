def minimum_rows(n, x, weights):
    weights.sort()  
    left = 0
    right = n - 1
    rows = 0

    while left <= right:
        if weights[left] + weights[right] <= x:
            left += 1  
        right -= 1  
        rows += 1  

    return rows

if __name__ == "__main__":
    n, x = map(int, input().split())
    weights = list(map(int, input().split()))

    result = minimum_rows(n, x, weights)

    print(result)