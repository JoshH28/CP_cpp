def sus(sad,joy):
 n,m=len(sad),len(joy)
 if abs(n-m)>1:return"No"
 i=j=panic=0
 while i<n and j<m:
  if sad[i]!=joy[j]:
   if panic:return"No"
   panic=1
   if n>m:i+=1
   elif n<m:j+=1
   else:i+=1;j+=1
  else:i+=1;j+=1
 if i<n or j<m:
  if panic:return"No"
 return"Yes"
k = int(input())
sad=input().strip()
joy=input().strip()
print(sus(sad,joy))
