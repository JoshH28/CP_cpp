def main():
    sus = input().strip()
    if (len(sus)%2):
        return "No"
    dic = {}
    
    for i in range(len(sus)//2):
        if (sus[2*(i+1) - 2] != sus[2*(i+1) - 1]):
            return "No"
    for i in sus:
        if (i not in dic.keys()):
            dic[i] = 1
        else:
            dic[i] += 1
    for i in dic.keys():
        if (dic[i]!=2):
            return "No"
    return "Yes"
print(main())