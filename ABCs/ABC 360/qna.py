a, b = map(int, input().strip().split())
if (a == b):
    print(1)
elif ((a-b)%2):
    print(2)
else:
    print(3)