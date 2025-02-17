n, m = map(int, input().split())
arr = list(map(int, input().split()))
ans = []
for i in range(1, n+1):
  if (i not in arr):
    ans.append(i)
print(len(ans))
for i in ans:
  print(i, end=" ")