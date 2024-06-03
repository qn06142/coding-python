def maxProduct(arr, n):

    arr.sort()
    num1 = num2 = 0

    sum1 = arr[0] * arr[1]

    sum2 = arr[n - 1] * arr[n - 2]
    if (sum1 > sum2):
        num1 = arr[0]
        num2 = arr[1]
    else:
        num1 = arr[n - 2]
        num2 = arr[n - 1]
    print(num1 * num2)
n = int(input())
arr = [int(i) for i in input().split()]
maxProduct(arr, n) 

#Wheatley1901