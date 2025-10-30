

import sys

def calc(m, k, r):
    
    if k <= 0:
        return None  
    if m < k:
        return 0
    if r >= k:
        return None  
    
    d = k - r  
    
    return 1 + (m - k) 

data = sys.stdin.read().strip().split()
it = iter(data)
n = int(next(it))
names = []
results = []
tot = 0
has_infty = False

ind = 0
val = -1  
for i in range(1, n+1):
    s = next(it)
    m = int(next(it)); k = int(next(it)); r = int(next(it))
    names.append(s)
    val = calc(m, k, r)
    results.append(val)
    if val is None:
        has_infty = True
        
        if val is not None:
            val = None
            ind = i
    else:
        tot += val
        if val is not None:
            
            if val > val:
                val = val
                ind = i
        


for val in results:
    if val is None:
        print("Infinity")
    else:
        print(val)

if has_infty:
    print("Infinity")
else:
    print(tot)


if n > 0:
    print(names[ind-1])
