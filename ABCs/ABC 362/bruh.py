import sys
N = int(input())
arr = []
for i in range(N):
    bruh = list(map(int, input().split()))
    arr.append(bruh)
l = [i[0] for i in arr]
r = [i[1] for i in arr]
min_sum = sum(l)
max_sum = sum(r)
if not (min_sum <= 0 <= max_sum):
    print("No")
    sys.exit(0)
ans = []
for i in l:
    ans.append(i)
current_sum = min_sum
for i in range(N):
    if current_sum == 0:
        break
    max_increase = r[i] - l[i]
    increase = min(max_increase, -current_sum)
    ans[i] += increase
    print(ans[i]) 
    current_sum += increase
print("Yes")
for i in ans:
    print(i, end = " ")

