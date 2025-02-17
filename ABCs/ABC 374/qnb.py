word1 = input().strip()
word2 = input().strip()
if word1 == word2:
    print(0)
else:
    flag = 0
    for i in range(min(len(word1), len(word2))):
        if word1[i] !=word2[i]:
            print(i+1)
            flag = 1
            break
    if flag == 0:
        print(min(len(word1), len(word2))+1)