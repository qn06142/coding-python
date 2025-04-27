def can_assign(T, persons, cakes, p):
    n = len(persons)
    k = len(cakes)
    j = 0  
    for a in persons:

        if T < abs(a - p):
            return False

        L = (a + p - T) / 2
        R = (a + p + T) / 2

        while j < k and cakes[j] < L:
            j += 1

        if j < k and cakes[j] <= R:
            j += 1
        else:
            return False
    return True

def min_time(persons, cakes, p):
    persons.sort()
    cakes.sort()
    low = 0
    high = max(max(abs(p - a) for a in persons), max(abs(p - b) for b in cakes)) * 2
    ans = high
    while low <= high:
        mid = (low + high) // 2
        if can_assign(mid, persons, cakes, p):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans

if __name__ == '__main__':

    persons = [10, 25, 40]
    cakes = [8, 15, 20, 35, 50]
    p = 30
    print(min_time(persons, cakes, p))