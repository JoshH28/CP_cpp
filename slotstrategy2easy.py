import math
mod = int(input())
str1 = input()
str2 = input()
str3 = input()
ans = 1e9
for q in range(3*mod):
  for w in range(3*mod):
    for r in range(3*mod):
      if str1[q%mod] == str2[w%mod] == str3[r%mod] and q != w != r:
        ans = min(ans, max(q, w, r))
if (ans == 1e9):
  print(-1)
else:
  print(ans)
    
  