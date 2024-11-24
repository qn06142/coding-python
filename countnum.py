def calculate_total_similarity(n, numbers):
    from collections import defaultdict

    # Initialize frequency dictionary for each digit place (0-8)
    digit_position_count = [defaultdict(int) for _ in range(9)]
    
    # Populate the frequency dictionary
    for number in numbers:
        str_num = str(number)[::-1]  # Reverse the number to process digits from unit place
        for i, digit in enumerate(str_num):
            digit_position_count[i][digit] += 1
    
    total_similarity = 0
    
    # Calculate the total similarity
    for number in numbers:
        str_num = str(number)[::-1]
        for i, digit in enumerate(str_num):
            count = digit_position_count[i][digit] - 1  # Exclude the number itself
            total_similarity += count
    
    return total_similarity // 2

# Example Usage
n = int(input())
numbers = list(map(int, input().split()))
print(calculate_total_similarity(n, numbers))
