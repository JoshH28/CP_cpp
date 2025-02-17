bruh = list(input().strip().split('|'))
for i in bruh:
    if (len(i) == 0):
        continue
    print(len(i), end = " ")