# [Verse 1]
# Found you when your heart was broke
# I filled your cup until it overflowed
# Took it so far to keep you close (Keep you close)
# I was afraid to leave you on your own (Ooh)

# [Pre-Chorus]
# I said I'd catch you if you fall (Fall)
# And if they laugh, then fuck 'em all (All)
# And then I got you off your knees
# Put you right back on your feet
# Just so you could take advantage of me

# [Chorus]
# Tell me, how's it feel sittin' up there?
# Feelin' so high, but too far away to hold me
# You know I'm the one who put you up there
# Name in the sky, does it ever get lonely?
# Thinkin' you could live without me
# Thinkin' you could live without me
# Baby, I'm the one who put you up there
# I don't know why (Yeah, I don't know why)
# Thinkin' you could live without me
# Live without me
# Baby, I'm the one who put you up there
# I don't know why (I don't know why, yeah, yeah)

# Gave love 'bout a hundred tries (Hundred tries)
# Just runnin' from the demons in your mind
# Then I took yours and made 'em mine (Mine)
# I didn't notice 'cause my love was blind

# [Pre-Chorus]
# Said I'd catch you if you fall (Fall)
# And if they laugh, then fuck 'em all (All)
# And then I got you off your knees
# Put you right back on your feet
# Just so you could take advantage of me

# [Chorus]
# Tell me, how's it feel sittin' up there?
# Feelin' so high, but too far away to hold me
# You know I'm the one who put you up there
# Name in the sky, does it ever get lonely?
# Thinkin' you could live without me
# Thinkin' you could live without me
# Baby, I'm the one who put you up there
# I don't know why (Yeah, I don't know why)
# Thinkin' you could live without me
# Live without me
# Baby, I'm the one who put you up there
# I don't know why, yeah
# [Bridge]
# You don't have to say just what you did (What you did)
# I already know (I know)
# I had to go and find out from them (Oh-woah)
# So tell me, how's it feel? (Oh-woah)

# [Chorus]
# Tell me, how's it feel sittin' up there?
# Feelin' so high, but too far away to hold me
# You know I'm the one who put you up there
# Name in the sky, does it ever get lonely?
# Thinkin' you could live without me
# Thinkin' you could live without me
# Baby, I'm the one who put you up there
# I don't know why (Yeah, I don't know why)

n = int(input())
grow = [0 for i in range(n)]
start = [0 for i in range(n)]
for i in range(n):
    grow[i], start[i] = map(int, input().split())

lo, hi = 1, n * 10**9

while (lo < hi):
    mid = (lo+hi)//2
    cut = [False for i in range(n)]
    flag = False
    for i in range(n):
        maxi = max(grow[i]*i)
