n = int(input())
flag = 0
for i in range(1, 30):
  if (i**i == n):
    flag = 1
    print(i)
    break
if flag==0:
  print(-1)