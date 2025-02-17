# // I think we're over-bored
# // Fighting in the backseat, saying things we don't mean
# // We can't keep score no more
# // Write our names in concrete, drunk at after-parties
# // I turned my hotel room
# // Into a garden, into a garden
# // Flying to France, Toulouse
# // I was too honest, a little too honest
# // 21 when I told her love's like an atom bomb
# // Pressing down on your shoulders
# // Put my thoughts in a folder, bury them 'til I'm dead and gone
# // Don't read them out, they're way too dumb
# // Lost myself intoxicated
# // Everybody wants to be somebody but nobody's there for you
# // Guess I-I, love you and I hate it
# // If you loved me then why would you leave? I'm stuck, all I see is you
# // Slow dancing on your bed
# // Kissing you to Coldplay, love me in the same way
# // I've pictured in my head
# // Take me into your place, throw me out the same day
# // I turned my hotel room
# // Into a garden, into a garden
# // Flying to France, Toulouse
# // I was too honest, a little too honest
# // 21 when I told her love's like an atom bomb
# // Pressing down on your shoulders
# // Put my thoughts in a folder, bury them 'til I'm dead and gone
# // Don't read them out, they're way too dumb
# // Lost myself intoxicated
# // Everybody wants to be somebody but nobody's there for you
# // Guess I-I, love you and I hate it
# // If you loved me then why would you leave? I'm stuck, all I see is you
import itertools  
n, k = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0
if (k <= n-k):
  for gay in itertools.combinations(arr, k):
    xor = 0
    for i in gay:
        xor ^= i
    ans = max(ans, xor)
else:
  yes = 0
  for i in arr:
    yes ^= i
  for a in itertools.combinations(arr, n-k):
    xor = yes
    for i in a:
      xor ^= i
    ans = max(ans, xor)
print(ans)
