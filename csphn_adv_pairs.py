def count_visible_pairs(heights):
    n = len(heights)
    count = 0
    
    for i in range(n):
        for j in range(i + 1, n):
            visible = True
            min_height = min(heights[i], heights[j])
            for k in range(i + 1, j):
                if heights[k] >= min_height:
                    visible = False
                    break
            if visible:
                count += 1
                #print(i, j)
    
    return count

# Example usage
if __name__ == "__main__":
    n = int(input())
    heights = list(map(int, input().split()))
    result = count_visible_pairs(heights)
    print(result)
