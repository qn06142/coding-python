import sys
import threading
import bisect
import heapq

input_data = sys.stdin

def solve():
    data = input_data.readline
    t = int(data().strip())
    for _ in range(t):
        s = data().strip()
        k = int(data().strip())
        m = len(s)

        prev = [i-1 for i in range(m)]
        next = [i+1 for i in range(m)]
        next[m-1] = -1
        prev[0] = -1

        alive = [True] * m
        time_del = [0] * m  

        heap = []
        for i in range(m-1):
            if s[i] > s[i+1]:
                heapq.heappush(heap, i)

        tail = m-1
        head = 0

        for step in range(1, m+1):

            while heap:
                i = heapq.heappop(heap)
                if alive[i]:
                    j = next[i]
                    if j != -1 and s[i] > s[j]:

                        break

                i = -1

            if heap or (i != -1 and alive[i] and next[i] != -1 and s[i] > s[next[i]]):

                pass
            else:

                i = tail

            time_del[i] = step
            alive[i] = False

            u = prev[i]
            v = next[i]

            if u != -1:
                next[u] = v
            else:
                head = v
            if v != -1:
                prev[v] = u
            else:
                tail = u

            if u != -1 and v != -1 and s[u] > s[v]:
                heapq.heappush(heap, u)

        def prefix_len(i):

            return i * (2*m - i + 1) // 2

        lo, hi = 1, m
        while lo < hi:
            mid = (lo + hi) // 2
            if prefix_len(mid) >= k:
                hi = mid
            else:
                lo = mid + 1
        p = lo

        d = p - 1
        P_prev = prefix_len(p-1)  
        offset = k - P_prev       

        cnt = offset
        answer_char = '?'
        for i in range(m):
            if time_del[i] > d:
                cnt -= 1
                if cnt == 0:
                    answer_char = s[i]
                    break

        sys.stdout.write(answer_char + "\n")

if __name__ == "__main__":

    threading.Thread(target=solve).start()