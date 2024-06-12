class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True

    def is_subsequence(self, word):
        node = self.root
        for char in word:
            if char in node.children:
                node = node.children[char]
            else:
                return False
        return node.is_end

def generate_subsequences(x, n):
    subsequences = set()
    dp = [[set() for _ in range(len(x) + 1)] for _ in range(n + 1)]
    
    for i in range(len(x) + 1):
        dp[0][i].add("")
    
    for length in range(1, n + 1):
        for i in range(1, len(x) + 1):
            dp[length][i] = dp[length][i-1].copy()
            for subseq in dp[length-1][i-1]:
                dp[length][i].add(subseq + x[i-1])
    
    return dp[n][len(x)]

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    m = int(data[0])
    n = int(data[1])
    k = int(data[2])
    
    x = data[3]
    y = data[4]
    
    given_subsequences = data[5:5+m]

    # Generate all subsequences of length n from x
    x_subsequences = generate_subsequences(x, n)
    
    # Build Trie for y
    y_trie = Trie()
    for subseq in generate_subsequences(y, n):
        y_trie.insert(subseq)
    
    # Filter valid subsequences
    valid_subsequences = []
    for subseq in x_subsequences:
        if not y_trie.is_subsequence(subseq):
            valid_subsequences.append(subseq)
    
    valid_subsequences.sort()
    
    # Find the positions of the given subsequences in the sorted list
    results = []
    from bisect import bisect_left
    
    for s in given_subsequences:
        if s in valid_subsequences:
            position = bisect_left(valid_subsequences, s) + 1
            results.append(position % k)
        else:
            results.append(-1)

    for result in results:
        print(result)

if __name__ == "__main__":
    main()