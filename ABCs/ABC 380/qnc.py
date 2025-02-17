n, k = map(int, input().split())
sus = input()
last, first, streak, flag = -1, -1, 0, 0
for i in range(n):
    if (sus[i] == '0'):
        if (streak):
            streak = 0
            k -= 1
            if (k == 0):
                flag = 1
                print(sus[:last+1] + sus[first: i] + sus[last+1: first] + sus[i:])
                break
            last = i-1
        else:
            continue
    else:
        if (streak==0):
            first = i
            streak = 1
        else:
            streak+=1
    if flag == 1:
        break
if (flag==0):
    print(sus[:last+1] + sus[first: n] + sus[last+1: first])
