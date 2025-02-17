n = int(input())
for i in range(n):
    gay = int(input())
    if (gay == 0):
        print("haha good one")
    elif (gay >= 180):
        print("canceled")
    else:
        print("berkeley"*int(gay/10) + "time")
        
        
    