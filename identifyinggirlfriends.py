gfNum, qnum = map(int, input().split())
query1 = {}
query2 = {}
for i in range(gfNum):
    gfname, gfnickname = input().split()
    query1[gfname] = gfnickname
    query2[gfnickname] = gfname

for i in range(qnum):
    queryType, query = input().split()
    if (queryType == "1"):
        print(query1[query])
    else:
        print(query2[query])