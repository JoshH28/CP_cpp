l, r = map(int, input().strip().split())
if ((l == 1 and r == 1) or (l == 0 and r == 0)):
    print("Invalid")
elif (l == 1 and r == 0):
    print("Yes")
else:
    print("No")