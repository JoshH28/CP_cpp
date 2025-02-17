def listProcess(numList):
    if (len(numList)>0):
        first = numList[0]
        print(len(numList), "|", end = " ")
        for i in numList:
            print(i, end=" ")
        for i in range(4 - len(numList)):
            print(" ", end=" ")
        print("|", first, "| ")
        numList = numList[1:]
        numList = listProcess(numList)
        numList.append(first)
        print(f"{len(numList)} |", end = " ")
        for i in numList:
            print(i, end=" ")
        for i in range(4 - len(numList)):
            print(" ", end=" ")
        print("| |")
        return numList
    else:
        print("0 | | | | | ")
        return numList

print(listProcess([3, 5, 10, 2]))

