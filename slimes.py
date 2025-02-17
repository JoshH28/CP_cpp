n = int(input())
s = input()
currChar = "1"
ans = 0
for i in s:
    if (currChar != i):
        ans += 1
        currChar = i
print(ans)
