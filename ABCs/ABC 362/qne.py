from collections import defaultdict

def count_arithmetic_subsequences(sequence):
    n = len(sequence)
    dp = [defaultdict(int) for _ in range(n)]
    total_count = [0] * (n + 1)
    
    for j in range(n):
        for i in range(j):
            d = sequence[j] - sequence[i]
            dp[j][d] += dp[i][d] + 1
            total_count[2] += 1  # every pair is an arithmetic sequence of length 2
            total_count[j - i + 1] += dp[i][d]
    
    return total_count

# Example usage
bruh = list(map(int, input().split()))
counts = count_arithmetic_subsequences(bruh)
for k in range(1, len(bruh) + 1):
    print(f"Number of arithmetic subsequences of length {k}: {counts[k]}")
