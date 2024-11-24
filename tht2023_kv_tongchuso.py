def sum_of_digits(n):
    return sum(int(digit) for digit in str(n))

def find_A_and_B(X):
    A = X // 2
    B = X - A
    
    sum_A = sum_of_digits(A)
    sum_B = sum_of_digits(B)
    
    while sum_A != sum_B:
        if sum_A < sum_B:
            A += 1
            B -= 1
        else:
            A -= 1
            B += 1
        sum_A = sum_of_digits(A)
        sum_B = sum_of_digits(B)
    
    return A, B

T = int(input())

for _ in range(T):
    X = int(input())
    A, B = find_A_and_B(X)
    print(A, B)