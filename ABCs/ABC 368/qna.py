n, k = map(int, input().strip().split())
arr = list(map(int, input().split()))
for i in range(n-k, n):
    print(arr[i], end=" ")
for i in range(n-k):
    print(arr[i], end=" ")