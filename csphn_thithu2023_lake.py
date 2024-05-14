def yeag(n): 
  
    # considering triplets in  
    # sorted order. The value  
    # of first element in sorted  
    # triplet can be at-most n/3. 
    results = []
    for i in range(1, int(n / 3) + 1):  
        for j in range(i + 1,  
                       int(n / 2) + 1):  
  
            k = n - i - j 
            if (i * i + j * j == k * k):
                results.append((i, j, k))
      
    return results
t = int(input())
#
for i in range(0, t):
    print(yeag(i))