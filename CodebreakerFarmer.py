#Random codebreaker generator
import requests
from bs4 import BeautifulSoup
import random
import time
tagDisplay = True

def unpackTags(s):
    returnStr = ""
    for i in s:
        returnStr += i
        returnStr += ", "
    return returnStr[:-3]

class Problem:
    def __init__(self, problemType, nameA, nameB, ACs, tags):
        self.problemType = problemType
        self.nameA = nameA
        self.nameB = nameB
        self.ACs = ACs
        self.tags = tags

    def __str__(self):
        if tagDisplay:
            return f"{self.problemType} - {self.nameA} / {self.nameB} - {self.ACs}ACs - Tags:{unpackTags(self.tags)}"
        else:
            return f"{self.problemType} - {self.nameA} / {self.nameB} - {self.ACs}ACs"


def ACreturn(problemA):
    return problemA.ACs

def returnSecondElement(a):
    return a[1]
    

refresh = input("Refresh cache? (Y/N)\nThis is always required for the first time running the program.\n")
pageContent = ""

if refresh == 'Y':
    URL = "http://codebreaker.xyz"
    page = requests.get(URL)
    cacheFile = open("CodebreakerCache.txt", 'wb')
    cacheFile.write(page.text.encode('utf8'))
    cacheFile.close()

    cacheFile = open("CodebreakerCache.txt", 'rb')
    pageContent = cacheFile.read().decode('utf8')
    cacheFile.close()
    print("Data retrieval successful.")
else:
    cacheFile = open("CodebreakerCache.txt", 'rb')
    pageContent = cacheFile.read().decode('utf8')
    cacheFile.close()
    print("Cache file read successfully.")
    

soup = BeautifulSoup(pageContent, "html.parser")

'''
xmas!
N/A!
ⓘTags: Syntax
						
							xmas!
NOI 2009!
Batch!
211!
'''
while True:
    displayNum = int(input("How many randomised problems do you want displayed?\n"))
    print("")
    filters = input("Enter in additional parameters separated by spaces.\nu=shoryu386 means only including unsolved problems for user shoryu386.\nac=50-100 means only allowing problems between 50 and 100 ACs.\nr=shoryu386 means that the program will recommend some unsolved problems to solve based on shoryu386's ranking. (overrides all other options, may take up to 30 seconds.)\nc=nameA,nameB means the program will compare the two people's solved problems.\n")
    excludedList = []
    name = ""
    minAC = 0
    maxAC = 10000
    recommendee = ""
    compareA = ""
    compareB = ""
    for i in filters.split(" "):
        if i[0:2] == "u=":
            name = i[2:]
            page2 = requests.get("http://codebreaker.xyz/profile/" + name)
            soup2 = BeautifulSoup(page2.content, "html.parser")
            tdNum = 0
            meaninglessNum = 0
            for solved in soup2.find_all('td'):
                if tdNum < 4 or solved.text.strip(" ") == "":
                    tdNum += 1
                    meaninglessNum += 1
                    continue
                excludedList.append(solved.text.strip(" "))
                tdNum += 1
            
            if tdNum != 0:
                input(f"{tdNum-meaninglessNum} solved problems omitted from search by username.")
            else:
                input("No problems were detected as solved. You may have entered in the wrong username.")
        elif i[0:3] == "ac=":
            temp = i[3:]
            minAC = int(temp.split("-")[0])
            maxAC = int(temp.split("-")[1])
        elif i[0:2] == "r=":
            recommendee = i[2:]
        elif i[0:2] == "c=":
            meow = i[2:]
            compareA, compareB = meow.split(",")
    if recommendee == "" and compareA =="" and compareB == "":
        curProblem = Problem("", "", "", 0, [])
        problemDataAll = soup.find_all('tr')[1:]
        problemsAll = []
        acExclusionNum = 0
        for tableRow in problemDataAll:
            for i in range(6):
                tds = tableRow.find_all('td')
                if (i == 0):
                    curProblem.nameA = tds[i].text.strip()
                    if curProblem.nameA in excludedList:
                        curProblem = Problem("", "", "", 0, [])
                        break
                elif (i == 1):
                    continue
                elif (i == 2):
                    temp = tds[i].text.strip()
                    curProblem.nameB = temp.split("\t")[-1]
                    curProblem.tags = (temp.split("\t")[0])[6:].split(", ")
                elif (i == 3):
                    continue
                elif (i == 4):
                    curProblem.problemType = tds[i].text.strip()
                elif (i == 5):
                    curProblem.ACs = int(tds[i].text.strip())
                    if curProblem.ACs > maxAC or curProblem.ACs < minAC:
                        curProblem = Problem("", "", "", 0, [])
                        acExclusionNum += 1
                        break
            if curProblem.nameA != "":
                problemsAll.append(curProblem)
            curProblem = Problem("", "", "", 0, [])
            
        if (not minAC == 0) or (not maxAC == 10000):
            if name != "":
                input(f"{acExclusionNum} further problems omitted from search by AC boundaries.")
            else:
                input(f"{acExclusionNum} problems omitted from search by AC boundaries.")
        random.shuffle(problemsAll)
        problemData = problemsAll[:displayNum]
        problemData.sort(reverse=True, key=ACreturn)

        for i in problemData:
            print(i)

        print(f"{len(problemData)} problems found.\n")
    elif compareA != "" and compareB != "":
        page2 = requests.get("http://codebreaker.xyz/profile/" + compareA)
        soup2 = BeautifulSoup(page2.content, "html.parser")
        tdNum = 0
        solvedA = []
        solvedB = []
        
        for solved in soup2.find_all('td'):
            if tdNum < 4 or solved.text.strip(" ") == "":
                tdNum += 1
                continue
            solvedA.append(solved.text.strip(" "))
            tdNum += 1
        
        page2 = requests.get("http://codebreaker.xyz/profile/" + compareB)
        soup2 = BeautifulSoup(page2.content, "html.parser")
        tdNum = 0

        for solved in soup2.find_all('td'):
            if tdNum < 4 or solved.text.strip(" ") == "":
                tdNum += 1
                continue
            solvedB.append(solved.text.strip(" "))
            tdNum += 1
        
        AbutNotB = []
        BbutNotA = []

        for i in solvedA:
            if not i in solvedB:
                AbutNotB.append(i)
            
        for i in solvedB:
            if not i in solvedA:
                BbutNotA.append(i)

        print(f"{compareA} solved but not {compareB}:")
        for i in AbutNotB:
            print(i)
        
        print("\n\n")
        print(f"{compareB} solved but not {compareA}:")
        for i in BbutNotA:
            print(i)



        

    else:
        page2 = requests.get("http://codebreaker.xyz/rankings")
        soup2 = BeautifulSoup(page2.content, "html.parser")

        rankings = soup2.find_all('tr')
        trueRanks = []
        curIndex = 0
        recommendeeIndex = -1
        firstAns = 1
        for row in rankings:
            if firstAns == 1:
                firstAns = 0
                continue
            trueRanks.append(row.text.split(' ')[1].strip()) #contains all names in ranking
            if trueRanks[curIndex] == recommendee:
                recommendeeIndex = curIndex
            curIndex += 1

        if recommendeeIndex == -1:
            print("The requested username was not found. Please check for typos in your request and try again.")
            continue

        scanRange = int(input("How many places up and down the ranking should it scan? This number is limited to 10 to minimise spam.\n"))
        scanRange = min(10, scanRange)
        clearedCount = {}
        for index in range(scanRange*2 + 1):
            time.sleep(1)
            if index == scanRange:
                print(str(index+1) + " items processed.")
                continue

            page3 = requests.get("http://codebreaker.xyz/profile/" + trueRanks[index + recommendeeIndex - scanRange])
            soup3 = BeautifulSoup(page3.content, "html.parser")
            tdNum = 0
            for solved in soup3.find_all('td'):
                if tdNum < 4 or solved.text.strip(" ") == "":
                    tdNum += 1
                    continue
                if solved.text.strip(" ") in clearedCount:
                    clearedCount[solved.text.strip(" ")] += 1
                else:
                    clearedCount[solved.text.strip(" ")] = 1
                tdNum += 1

            print(str(index+1) + " items processed.")

        userSolved = []
        page3 = requests.get("http://codebreaker.xyz/profile/" + trueRanks[recommendeeIndex])
        soup3 = BeautifulSoup(page3.content, "html.parser")
        for solved in soup3.find_all('td'):
            if tdNum < 4 or solved.text.strip(" ") == "":
                tdNum += 1
                continue
            userSolved.append(solved.text.strip(" "))
            tdNum += 1


        outputList = []
        for probName, probCount in clearedCount.items():
            if probName in userSolved:
                continue
            outputList.append([probName, probCount])

        outputList.sort(key=returnSecondElement, reverse=True)
        for prob in outputList:
            print(prob[0] + " " + str(prob[1]))

        print(str(len(outputList)) + " problems were found.")
            

            
            
        
    continueInput = input("Continue? (Y/N)")
    if continueInput != "Y":
        print("See you again!")
        break
