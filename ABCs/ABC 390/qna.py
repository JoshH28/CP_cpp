a = list(map(int, input().split()))
cnt = 0
for i in range(len(a)-1):
    if a[i] > a[i+1]:
        a[i], a[i+1] = a[i+1], a[i]
        cnt+=1
if (cnt == 1):
    print("Yes")
else:
    print("No")