n = int(input())
for i in range(n):
    sus = input()
    word = "calico"
    word = word[::-1]
    flag = False
    for i in range(len(word)):
        gay = word[:i+1]
        gay = gay[::-1]
        if sus.startswith(gay):
            print("CALICO" + sus[i+1:])
            flag = True
            break
    if (flag==False):
        print(sus)
        
        
    