arr = []
def sus(string, index):
  first_s = string[0:index-1] + string[index] + string[index-1] + string[index+1:]
  if (first_s not in arr):
    arr.append(first_s)
  second_s = string[0:index] + string[index+1] + string[index] + string[index+2:]
  if (second_s not in arr):
    arr.append(second_s)
  #print(first_s, second_s)

s = input()
arr.append(s)
for i in range(1, len(s)-1):
  sus(s, i)
print(len(arr))