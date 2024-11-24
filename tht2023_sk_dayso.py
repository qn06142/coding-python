import random
import subprocess
from typing import List

def max_sum_subarray(n: int, L: int, R: int, arr: List[int]):
    pre = [0] * n

    # calculating prefix sum
    pre[0] = arr[0]
    for i in range(1, n):
        pre[i] = pre[i - 1] + arr[i]

    s1 = set()
    s1.add(0)
    ans = float('-inf')

    ans = max(ans, pre[L - 1])

    # we maintain flag to
    # counter if that initial
    # 0 was erased from set or not.
    flag = 0

    for i in range(L, n):

        # erase 0 from multiset once i=b
        if i - R >= 0:
            if flag == 0:
                s1.remove(0)
                flag = 1

        # insert pre[i-L]
        if i - L >= 0:
            s1.add(pre[i - L])

        # find minimum value in multiset.
        ans = max(ans, pre[i] - min(s1))

        # erase pre[i-R]
        if i - R >= 0:
            s1.remove(pre[i - R])

    return ans
while True:
    # Generate random inputs
    n = int(2e5)
    L = random.randint(int(1), int(n))
    R = random.randint(int(L), int(n))
    arr = [random.randint(int(-1e9), int(1e9)) for _ in range(n)]

    # Call the function and get the result
    result = max_sum_subarray(n, L, R, arr)

    # Prepare the input for the other script
    input_str = f"{n} {L} {R}\n" + " ".join(str(x) for x in arr)

    # Run the other script
    proc = subprocess.run(["tht2023_sk_dayso.exe"], input=input_str, text=True, capture_output=True)

    # Get the output of the other script
    other_output = proc.stdout.strip()

    # Compare the outputs
    if str(result) == other_output:
        
        print(other_output, result, flush=True)
        #print('\b' * len("The outputs are the same."), end='', flush=True)
        pass
    else:
        with open("tmp.inp", "w") as f:
            f.write(input_str)
        print("The outputs are different.")
        print(result)
        print(proc.stdout.strip())
        break