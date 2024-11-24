import heapq
import sys

def process_commands(commands):
    max_heap = []
    element_count = 0
    freq = {}

    for command in commands:
        if command[0] == '+':
            value = int(command[1:])
            if element_count < 15000:
                heapq.heappush(max_heap, -value)
                if value in freq:
                    freq[value] += 1
                else:
                    freq[value] = 1
                element_count += 1
        elif command == '-':
            if element_count > 0:
                # Remove all occurrences of the current max element
                while max_heap:
                    max_value = -heapq.heappop(max_heap)
                    if freq[max_value] > 0:
                        freq[max_value] = 0
                        break
                element_count = sum(freq.values())

    # Collect remaining elements
    remaining_elements = []
    for value, count in freq.items():
        if count > 0:
            remaining_elements.extend([value] * count)

    remaining_elements.sort(reverse=True)
    
    # Output the result
    print(len(remaining_elements))
    for value in remaining_elements:
        print(value)

