import sys
lol = input()
flag = 1
ans = 1
for i in range(len(lol)//2):
    if lol[i] != lol[len(lol) - i - 1]:
        flag = 0
        break
if flag:
    print(len(lol))
if (len(lol) == 2):
    print(1)
    sys.exit()
for i in range(len(lol)-2):
    if lol[i] == lol[i+1]: #palindrome hit, start checking
        l = i
        r = i+1
        while(lol[l] == lol[r] and l >= 0 and r < len(lol)):
            l-=1
            r+=1
        ans = max(ans, r-l+1)
    elif lol[i] == lol[i+2]:
        l = i
        r = i+2
        while(lol[l] == lol[r] and l >= 0 and r < len(lol)):
            l-=1
            r+=1
        l+=1
        r-=1
        ans = max(ans, r-l+1)
print(ans)
        
        
