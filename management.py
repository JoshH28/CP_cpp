n = int(input())
arr = list(map(int, input().split()))
gay = {}
for i in range(1, n+1, 1):
    gay[i] = 0
for i in arr:
    gay[i] += 1
for i in range(1, n+1, 1):
    print(gay[i])
    