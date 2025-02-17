n = int(input())
a = list(map(int, input().split()))
cr = a[0] / a[1]
flag = 0
for i in range(1, n-1):
  if (a[i] / a[i+1] != cr):
    flag = 1
if (flag == 0):
  print("Yes")
else:
  print("No")
