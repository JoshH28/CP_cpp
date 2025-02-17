def find_spoiled_bottle(N):
    bottles = list(range(1, N+1))
    friends = []
    for i in range(1, N+1):
      friend = [bottle for bottle in bottles if bin(bottle).count('1') == i]
      if (len(friend) == 0):
        continue
      print(len(friend), end = " ")
      for i in friend:
        print(i, end = " ")
      friends.append(friend)
      print()
    ino = input()  
    upset_friends = []
    for i in range(len(ino)):
      if ino[i] == '1':
        upset_friends.append(i+1)

    # Step 4: Identify the Spoiled Bottle
    spoiled_bottle = 0
    for friend in upset_friends:
        spoiled_bottle ^= friend

    print(f"The spoiled bottle is: {spoiled_bottle}")

# Example Usage
n = int(input())
find_spoiled_bottle(n)