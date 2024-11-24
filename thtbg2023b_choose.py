from bisect import bisect
def max_items_can_buy(n, m, buy_prices, sell_prices, queries):
    for budget in queries:
        currbudget = budget
        count = 0
        for i in items:
            currbudget += i
            count += 1
            if currbudget < 0:
                count -= 1
                break
            if currbudget == 0:
                break
        yield count
n, m = tuple(int(i) for i in input().split())
buy_prices = [int(i) for i in input().split()]
sell_prices = [int(i) for i in input().split()]
items = list((sell_prices[i] - buy_prices[i] for i in range(0, n)))
items.sort(reverse=True)
#print(items)
queries = [int(i) for i in input().split()]
results = max_items_can_buy(n, m, buy_prices, sell_prices, queries)
for result in results:
    print(result)
