n = int(input())
arr=list(map(int, input().split()))
arr.sort()
arr.reverse()
counter = 0
ans = 0
for i in arr:
    counter += 1
    if(counter%4 == 0):
        continue
    ans+=i
print(ans)