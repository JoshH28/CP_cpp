import math
n = int(input())

a = []
b = []
c = []

for i in range(0, n):
    gei = list(map(int, input().split()))
    a.append(gei[0])
    b.append(gei[1])
    c.append(gei[2])

dp = [[-1 for i in range(0, 3)] for q in range(0, n)]


def recur(index, prev):
    if (index == n):
        return 0
    if (dp[index][prev] != -1):
        return dp[index][prev]
    cmax = 0
    if (prev != 0):
        cmax = max(cmax, recur(index+1, 0) + a[index])
    if(prev != 1):
        cmax = max(cmax, recur(index+1, 1) + b[index])
    if (prev != 2):
        cmax = max(cmax, recur(index+1, 2) + c[index])
    dp[index][prev] = cmax
    return cmax

print(max({recur(1, 0)+a[0], b[0] + recur(1, 1), c[0] + recur(1, 2)}))