ch, n = input().split()
n = int(n)

new_char = chr((ord(ch) - ord('a') + n) % 26 + ord('a'))

print(new_char)
