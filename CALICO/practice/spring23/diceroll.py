tc = int(input())
for i in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))
    mp = {}
    for q in arr:
        if (q not in mp.keys()):
            mp[q] = 1
        else:
            mp[q] += 1
    lol = []
    for i in mp.keys():
        lol.append((i, i * mp[i]))
    lol = sorted(lol, key=lambda x: x[1], reverse=True)
    print(lol[0][0])