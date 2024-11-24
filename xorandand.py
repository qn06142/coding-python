def max_value(arr, idx, current_value):
    if idx == len(arr):
        return current_value

    result_xor = max_value(arr, idx + 1, current_value ^ arr[idx])

    result_and = max_value(arr, idx + 1, current_value & arr[idx])

    return max(result_xor, result_and)

n = int(input())  
arr = list(map(int, input().split()))  

result = max_value(arr, 1, arr[0])

print(result)
