s = input()
t = input()
arr = []
while (s != t):
    temp = []
    for i in range(len(s)):
        if s[i] != t[i]:
            temp.append(s[:i] + t[i] + s[i+1:])
    temp.sort()
    arr.append(temp[0])
    s = temp[0]
print(len(arr))
for i in arr:
    print(i)