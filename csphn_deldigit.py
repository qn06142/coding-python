def delete_digits(s, k):
    stack = []
    for digit in s:
        while k > 0 and stack and stack[-1] < digit:
            stack.pop()
            k -= 1
        stack.append(digit)
    while k > 0:
        stack.pop()
        k -= 1
    return ''.join(stack)

def solve():
    s = input().strip()
    k = int(input().strip())
    result = delete_digits(s, k)
    print(result)

solve()
