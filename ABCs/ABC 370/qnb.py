n = int(input())
arr = []
for i in range(n):
    gay = list(map(int, input().strip().split()))
    arr.append(gay)
curr = arr[0][0]
for i in range(2, n+1):
    curr=arr[max(curr-1, i-1)][min(curr-1, i-1)]
print(curr)
    