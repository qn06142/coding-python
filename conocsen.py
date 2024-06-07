def snail_journey():
    with open('OCSEN.INP', 'r') as file:
        a, b, v = map(int, file.readline().split())

    day_distance = a - b
    days = (v - b - 1) // day_distance + 1
    total_distance = days * a - (days - 1) * b

    with open('OCSEN.OUT', 'w') as file:
        file.write(f'{days} {total_distance}')

snail_journey()
