import math as gay
n = int(input())
arr = list(map(int, input().split()))
# for i in arr:
#     print(i)
dp = []
dp.append(0)
for i in range(1, n):
    dp.append(gay.inf)
    # print(dp[i])
for q in range (0, n):
    for i in range(1, 3):
        if q+i >= n:
            continue
        dp[q+i] = min(dp[q]+abs(arr[q+i]-arr[q]),dp[q+i])
print(dp[n-1])
