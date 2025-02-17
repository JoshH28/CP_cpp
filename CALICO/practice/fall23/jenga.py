import math
tc = int(input())
precalc = [0, 2]
mod = 3359232
for i in range(2, 350):
    precalc.append(precalc[-1]*2)
print()
for boyinspace in range(tc):
    n = int(input())
    ans = 0
    for i in range(math.floor(n/3)+1):
        ans += (precalc[i]%mod)
        ans%=mod
    print(ans)