def count_char(matrix, top, left, bottom, right, char):
    count = 0
    for i in range(top, bottom + 1):
        for j in range(left, right + 1):
            if matrix[i][j] == char:
                count += 1
    return count

def max_beautiful_submatrix(matrix, m, n, k):
    max_area = 0

    for top in range(m):
        for left in range(n):
            for bottom in range(top, m):
                for right in range(left, n):
                    count_A = count_char(matrix, top, left, bottom, right, 'A')
                    count_B = count_char(matrix, top, left, bottom, right, 'B')
                    if abs(count_A - count_B) <= k:
                        area = (bottom - top + 1) * (right - left + 1)
                        max_area = max(max_area, area)

    return max_area

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    T = int(data[idx])
    idx += 1
    
    results = []
    
    for _ in range(T):
        m = int(data[idx])
        n = int(data[idx + 1])
        k = int(data[idx + 2])
        idx += 3
        
        matrix = []
        for i in range(m):
            matrix.append(data[idx])
            idx += 1
        
        result = max_beautiful_submatrix(matrix, m, n, k)
        results.append(result)
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()