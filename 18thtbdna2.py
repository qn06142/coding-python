def longest_covered_segment(banners):
    banners.sort(key=lambda x: x[0])
    longest_segment = 0
    current_segment = [banners[0][0], banners[0][1]]
    for i in range(1, len(banners)):
        if banners[i][0] <= current_segment[1]:
            current_segment[1] = max(current_segment[1], banners[i][1])
        else:
            longest_segment = max(longest_segment, current_segment[1] - current_segment[0])
            current_segment = [banners[i][0], banners[i][1]]
    longest_segment = max(longest_segment, current_segment[1] - current_segment[0])
    return longest_segment

banners = [[int(i) for i in input().split()] for j in range(0, int(input()))]

print(longest_covered_segment(banners))
