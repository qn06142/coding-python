import sys

MOD = 846103811092001

def sum(x):
    return x * (x + 1) // 2

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = [0] * (n + 1)
    for i in range(1, n + 1):
        a[i] = int(data[i])
    
    left = [0] * (n + 1)
    right = [0] * (n + 1)
    st = []

    for i in range(1, n + 1):
        while st and a[st[-1]] <= a[i]:
            st.pop()
        left[i] = st[-1] if st else 0
        st.append(i)

    st.clear()

    for i in range(n, 0, -1):
        while st and a[st[-1]] < a[i]:
            st.pop()
        right[i] = st[-1] if st else n + 1
        st.append(i)

    result = 0
    for i in range(1, n + 1):
        l = left[i]
        r = right[i]
        result += (((sum(i - l) * (r - i)) % MOD + (sum(r - i - 1) * (i - l)) % MOD) * a[i]) % MOD
        result %= MOD

    print(result)

if __name__ == "__main__":
    main()

