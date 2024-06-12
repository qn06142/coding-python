import heapq

def process_commands(commands):
    # Priority queue
    pq = []
    # Count of elements in the list
    count = 0
    # Dictionary to keep track of the frequency of elements
    freq = {}

    for command in commands:
        if command.startswith("+"):
            value = int(command[1:])
            if count < 15000:
                # Push negative value to use heapq as a max-heap
                heapq.heappush(pq, -value)
                if value in freq:
                    freq[value] += 1
                else:
                    freq[value] = 1
                count += 1
        elif command == "-":
            if count > 0:
                # Find the max element and remove it
                while pq:
                    max_value = -heapq.heappop(pq)
                    if freq[max_value] > 0:
                        freq[max_value] = 0
                        break
                count = sum(freq.values())

    # Extract remaining elements from the heap
    remaining_elements = []
    for value in freq:
        if freq[value] > 0:
            remaining_elements.extend([value] * freq[value])

    remaining_elements.sort(reverse=True)
    
    # Output the result
    print(len(remaining_elements))
    for value in remaining_elements:
        print(value)

from sys import stdin
commands = [line for line in stdin]
process_commands(commands)