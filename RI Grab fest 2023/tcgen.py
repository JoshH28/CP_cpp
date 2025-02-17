import random
n = random.randint(1, 4)
print(1, n, 1)
for i in range(n):
    print(random.randint(0, 4), end=" ")
print()
print(random.randint(1, n), random.randint(0, 4))