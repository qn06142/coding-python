n = int(input())
def swap_list_items(lst, index1, index2):
    lst[index1], lst[index2] = lst[index2], lst[index1]
    return lst
a = [int(i) for i in input().split()]
sorted = False
count = 0
while sorted == False:
    sorted = True
    for i in range(0, n-2):
        if a[i + 1] < a[i]:
            a = swap_list_items(a, i, i+1)
            count += 1
            sorted = False
print(count)
