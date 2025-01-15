def find_mth_number(N, K, M):
    count_per_segment = N // K

    segment_index = (M - 1) // count_per_segment

    if segment_index >= K:
        return -1
    if segment_index == 0:
        return M * K
    return segment_index + K * ((M - 1) % count_per_segment)

N, K, M = map(int, input().split())
print(find_mth_number(N, K, M))