mod = 1234567890

def count_occurrences(text, pattern):
    # Hàm đếm số lần xuất hiện của pattern trong text (có thể chồng chéo)
    count = 0
    start = 0
    while True:
        pos = text.find(pattern, start)
        if pos == -1:
            break
        count += 1
        start = pos + 1  # cho phép chồng chéo
    return count

def combine(state1, state2, S):
    m = len(S)
    # Tính số lần xuất hiện qua biên:
    cross_string = state1['suf'] + state2['pre']
    cross = count_occurrences(cross_string, S)
    
    new_state = {}
    new_state['occ'] = (state1['occ'] + state2['occ'] + cross) % mod
    
    # Xây tiền tố:
    if state1['len'] >= m - 1:
        new_state['pre'] = state1['pre']
    else:
        new_pre = state1['pre'] + state2['pre']
        new_state['pre'] = new_pre[:m-1]
    
    # Xây hậu tố:
    if state2['len'] >= m - 1:
        new_state['suf'] = state2['suf']
    else:
        new_suf = state1['suf'] + state2['suf']
        new_state['suf'] = new_suf[-(m-1):]
    
    # Cập nhật độ dài
    new_state['len'] = state1['len'] + state2['len']
    return new_state

def base_state(c, S):
    m = len(S)
    state = {}
    state['occ'] = 1 if c == S else 0  # xuất hiện chỉ khi xâu đơn bằng S
    state['pre'] = c
    state['suf'] = c
    state['len'] = 1
    return state

def fib_state(n, S, memo):
    # Sử dụng đệ quy nhân nhanh để tính state của fₙ
    if n in memo:
        return memo[n]
    if n == 1:
        memo[1] = base_state("A", S)
        return memo[1]
    if n == 2:
        memo[2] = base_state("B", S)
        return memo[2]
    # Vì fₙ = fₙ₋₁ + fₙ₋₂ theo định nghĩa
    state1 = fib_state(n-1, S, memo)
    state2 = fib_state(n-2, S, memo)
    memo[n] = combine(state1, state2, S)
    return memo[n]

# Đọc dữ liệu: mỗi dòng gồm số nguyên n và xâu s
import sys
for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    parts = line.split()
    n = int(parts[0])
    S = parts[1]
    memo = {}
    result_state = fib_state(n, S, memo)
    print(result_state['occ'] % mod)
