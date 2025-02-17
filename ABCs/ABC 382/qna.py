n, d = map(int, input().split())
sus = input()
cnt = 0
for i in sus:
    if i == '@':
        cnt+=1
cnt -= d
print(n-cnt)
