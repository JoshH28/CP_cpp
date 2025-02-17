
dp = [[-1 for i in range(101)] for q in range(10**5  +1 )]
weight = [0 for i in range(101)]
value = [0 for i in range(101)]
n,k = 0,0
def memo(idx, currweight):
    if(idx==n):
        return 0
    if dp[idx][currweight] != -1:
        return dp[idx][currweight]
    ans = 0
    if currweight+weight[idx] <= k:
        ans = max(ans, memo(idx+1, currweight+weight[idx]) + value[idx])
    ans = max(ans, memo(idx+1, currweight))
    dp[idx][currweight] = ans
    return ans
n, k = map(int, input().split())
for i in range(n):
    weight[i], value[i] = map(int, input().split())

print(memo(0, 0))