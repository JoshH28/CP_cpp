funny = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
bruh = input()
dic = {}
for i in range(len(bruh)):
    dic[bruh[i]] = i+1
ans = 0
current = "A"
for i in funny:
    ans += abs(dic[i] - dic[current])
    current = i
print(ans)