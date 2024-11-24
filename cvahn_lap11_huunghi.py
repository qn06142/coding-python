def TU(a):
    Tg = 0
    for i in range(1, a):
        if a % i == 0:
            Tg += i
    return Tg

n = int(input('Nhap so n: '))
for a in range(1, n+1):
    b = TU(a)
    if TU(b) == a:
        print(a, ' ', b)

