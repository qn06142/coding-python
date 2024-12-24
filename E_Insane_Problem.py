import math

def count_valid_pairs(t, test_cases):
    results = []
    for case in test_cases:
        k, l1, r1, l2, r2 = case
        count = 0
        for x in range(l1, r1 + 1):  
            if x > r2:  
                break

            lower_bound = math.ceil(math.log(max(l2 / x, 1), k))  
            upper_bound = math.floor(math.log(r2 / x, k))         

            if lower_bound <= upper_bound:  
                count += (upper_bound - lower_bound + 1)

        results.append(count)
    return results

t = int(input())  
test_cases = [tuple(map(int, input().split())) for _ in range(t)]

results = count_valid_pairs(t, test_cases)

for res in results:
    print(res)