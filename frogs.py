# Last Christmas I gave you my heart
# But the very next day you gave it away
# This year, to save me from tears
# I'll give it to someone special
# Last Christmas I gave you my heart
# But the very next day you gave it away
# This year, to save me from tears
# I'll give it to someone special
# Once bitten and twice shy
# I keep my distance, but you still catch my eye
# Tell me baby, do you recognize me?
# Well, it's been a year, it doesn't surprise me
# Happy Christmas, I wrapped it up and sent it
# With a note saying "I love you", I meant it
# Now I know what a fool I've been
# But if you kissed me now, I know you'd fool me again
# Last Christmas I gave you my heart
# But the very next day you gave it away
# This year, to save me from tears
# I'll give it to someone special
# Last Christmas I gave you my heart
# But the very next day you gave it away
# This year, to save me from tears
# I'll give it to someone special
# Ooh
# Oh, oh, baby
# A crowded room, friends with tired eyes
# I'm hiding from you and your soul of ice
# My God, I thought you were someone to rely on
# Me? I guess I was a shoulder to cry on
# A face on a lover with a fire in his heart
# A man under cover, but you tore me apart
# Oh, oh now I've found a real love
# You'll never fool me again
# Last Christmas I gave you my heart
# But the very next day you gave it away
# This year, to save me from tears
# I'll give it to someone special, special
# Last Christmas I gave you my heart
# But the very next day you gave it away
# This year, to save me from tears
# I'll give it to someone special
# Special
# A face on a lover with a fire in his heart (I gave you mine)
# A man under cover but you tore him apart
# Maybe next year I'll give it to someone
# I'll give it to someone special
# Special
# So long
import math
hn, fn, mn = map(int, input().split())
frogs = list(map(int, input().split()))
mos = list(map(int, input().split()))
dic = {}
for i in range(fn):
    dic[i] = 0
    for q in mos:
        if (q%frogs[i] == 0):
            dic[i] += 1

ans = []
mx = math.inf
for i in range(fn):
    print(dic[i], mx, end = " ")
    if (dic[i] == mx):
        ans.append(i)
    elif(dic[i] < mx):
        mx = dic[i]
        ans.clear()
        ans.append(i)
        print(i)
ans.sort()
print(len(ans))
for i in ans:
    print(i+1, end = " ")