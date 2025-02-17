pts = list(map(int, input().split()))
if (0 in pts):
    print("FAIL")
elif sum(pts) >= 85:
    print("GOLD")
elif sum(pts) >= 75:
    print("SILVER")
elif sum(pts) >= 61:
    print("PASS")
else:
    print("FAIL")