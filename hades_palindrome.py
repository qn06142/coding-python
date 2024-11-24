from sys import setrecursionlimit
setrecursionlimit(100000)

def is_palindrome(s):

    if len(s) <= 1:
        return True

    if s[0] != s[-1]:
        return False

    return is_palindrome(s[1:-1])

s = input().strip()

if is_palindrome(s):
    print("YES")
else:
    print("NO")