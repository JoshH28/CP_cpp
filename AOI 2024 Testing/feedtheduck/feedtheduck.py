import math

# Read inputs
n, budget = map(int, input().split())
t1, l, r, csum, best = 0, 0, 0, 0, math.inf
hold = list(map(int, input().split()))

# Initialize real list with cumulative sums
real = [0]
for i in hold:
    real.append(real[-1] + i)  # Append cumulative sum

# Sliding window to find the best solution
while l <= n:
    while r <= n and real[r] - real[l] < budget:
        r += 1
    if r <= n and real[r] - real[l] >= budget:
        best = min(best, real[r] - real[l])
    l += 1
if best == math.inf:
    print(-1)  # Indicating no solution found
else:
    print(best)
