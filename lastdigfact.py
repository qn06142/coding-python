print(str(str(eval(''.join(str(i) + '*' for i in range(1, n+1))[:-1]))[-1:] if n < 5 else 0) if not exec('n = int(input())') else 0)