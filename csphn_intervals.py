import math
import sys
input = sys.stdin.read
from bisect import bisect_left, bisect_right

def solve():
    data = input().split()
    n, q = map(int, data[:2])
    arr = list(map(int, data[2:2 + n]))
    queries = data[2 + n:]

    # Block size for sqrt decomposition
    block_size = int(math.sqrt(n)) + 1
    blocks = []
    block_sum = []

    # Initialize blocks and block sums
    for i in range(0, n, block_size):
        block = arr[i:i + block_size]
        blocks.append(block)
        block_sum.append(sum(block))

    # Cursor starts at the end of the array
    cursor = n

    # Process queries
    output = []
    query_index = 0
    while query_index < len(queries):
        op = queries[query_index]
        if op == 'A':
            # Insert x before cursor
            x = int(queries[query_index + 1])
            query_index += 1

            # Find the block and position where to insert
            block_idx = cursor // block_size
            pos_in_block = cursor % block_size

            # Insert into the block
            blocks[block_idx].insert(pos_in_block, x)
            block_sum[block_idx] += x

            # Rebalance blocks if necessary
            for i in range(block_idx, len(blocks)):
                if len(blocks[i]) > block_size:
                    if i == len(blocks) - 1:
                        # Create a new block if we're at the last block
                        blocks.append([blocks[i].pop()])
                        block_sum.append(blocks[-1][0])
                    else:
                        # Move the last element to the next block
                        element = blocks[i].pop()
                        blocks[i + 1].insert(0, element)
                        block_sum[i + 1] += element
                        block_sum[i] -= element

            cursor += 1

        elif op == 'D':
            # Delete the number before the cursor
            if cursor > 0:
                cursor -= 1

                # Find the block and position to delete
                block_idx = cursor // block_size
                pos_in_block = cursor % block_size

                # Remove from the block
                element = blocks[block_idx].pop(pos_in_block)
                block_sum[block_idx] -= element

                # Rebalance blocks if necessary
                for i in range(block_idx, len(blocks) - 1):
                    if len(blocks[i]) < block_size:
                        # Move the first element of the next block to the current block
                        element = blocks[i + 1].pop(0)
                        blocks[i].append(element)
                        block_sum[i] += element
                        block_sum[i + 1] -= element

                # Remove the last block if it becomes empty
                if len(blocks[-1]) == 0:
                    blocks.pop()
                    block_sum.pop()

        elif op == 'L':
            # Move cursor left
            if cursor > 0:
                cursor -= 1

        elif op == 'R':
            # Move cursor right
            if cursor < sum(len(block) for block in blocks):
                cursor += 1

        elif op == 'Q':
            # Query the sum from l to r
            l = int(queries[query_index + 1])
            r = int(queries[query_index + 2])
            query_index += 2

            # Find the blocks and positions
            block_l = l // block_size
            pos_l = l % block_size
            block_r = r // block_size
            pos_r = r % block_size

            # Calculate the sum
            total_sum = 0
            if block_l == block_r:
                # Both l and r are in the same block
                total_sum = sum(blocks[block_l][pos_l:pos_r + 1])
            else:
                # Sum the part of the left block
                total_sum += sum(blocks[block_l][pos_l:])
                # Sum the full blocks in between
                for i in range(block_l + 1, block_r):
                    total_sum += block_sum[i]
                # Sum the part of the right block
                total_sum += sum(blocks[block_r][:pos_r + 1])

            output.append(total_sum)

        query_index += 1

    # Print all query results
    sys.stdout.write('\n'.join(map(str, output)) + '\n')
solve()