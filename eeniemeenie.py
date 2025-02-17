n, k = map(int, input().split())
k %= n
names = list(input().split())
print(names[k])