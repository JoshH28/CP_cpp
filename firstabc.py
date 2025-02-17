n = int(input())
ans = 0
a = 0
b = 0
c = 0
s = input()
for i in s:
    if (i == 'A'):
        a = 1
    elif(i == 'B'):
        b = 1
    else:
        c = 1
    ans += 1
    if (a and b and c):
        print(ans)
        break