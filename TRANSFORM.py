def can_create_number(A, B):


  binary_b = bin(B)[2:]

  for i in range(len(binary_b)):
    if binary_b[i] == '1':

      if i % 2 == 0:

        A = A * 10 + 1
      else:

        A *= 2

  return A == B
print(*(can_create_number(*(int(i) for i in input().split())) for i in range(0, int(input()))))