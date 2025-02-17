n = int(input())
#print(f"0 0\n0 1\n0 0\n")
print(2+2+n*3)
print(f"0 0\n0 1")
for i in range(n):
  print(f"{i+1} {i}\n{i+1} {i+1}\n{i+1} {i+2}")
print(f"{n+1} {n}\n{n+1} {n+1}")