def count_triangles(n, A, B, C):
    # Sort the arrays
    A.sort()
    B.sort()
    C.sort()

    # Initialize the count
    count = 0

    # Use two pointers approach for each element in A
    for a in A:
        b_pointer = 0
        c_pointer = n - 1
        while b_pointer < n and c_pointer >= 0:
            # If the three numbers can form a triangle
            if a + B[b_pointer] > C[c_pointer]:
                # Add the possible combinations to the count
                count +=  c_pointer - b_pointer + 2
                # Move the b_pointer to the next element
                b_pointer += 1
            else:
                # Move the c_pointer to the previous element
                c_pointer -= 1

    # Return the count
    return count

n = int(input())
A = list(int(i) for i in input().split())
B = list(int(i) for i in input().split())
C = list(int(i) for i in input().split())

print(count_triangles(n, A, B, C))