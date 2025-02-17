n = int(input())
sus = list(input().split('U'))
ans = 0
for i in sus:
    lcnt, rcnt = 0, 0
    for q in i:
        if (q == 'L'):
            lcnt += 1
        elif (q == 'R'):
            rcnt += 1
    ans += max(rcnt, lcnt)
ans += len(sus)
print(ans)