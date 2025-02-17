yes = input()
cnt, skip = 0, 0
for i in range(len(yes)):
    if (skip):
        skip = 0
        continue
    if (yes[i] == '0' and i+1 != len(yes) and yes[i+1] == '0'):
        skip = 1
    cnt+=1
print(cnt)