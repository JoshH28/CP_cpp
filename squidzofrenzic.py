# [Intro]
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (Back to you)
# (Ooh-ooh-ooh, ooh-ooh-ooh)

# [Verse 1]
# Blink and then it's over
# Yeah, I think I'm getting older
# 'Cause I can waste away the days with all
# The things I wish I'd say, but then
# We blink and it's over

# [Pre-Chorus]
# So maybe I should put my heart out on the table
# And fuck it if it breaks
# And maybe I've been hiding from what I'm afraid of
# But I don't wanna wait

# [Chorus]
# No, I don't wanna ooh, ooh-ooh-ooh
# I'm always running so I can't get close to you
# But we don't got a lot of time to lose
# And all that I want is to finally be honest
# Yeah, ooh, ooh-ooh-ooh
# I'm always running but my feet lead back to you

# [Drop]
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (Back to you)
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (I'm always running but my feet lead back to you)
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (Back to you)
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (I'm always running but my feet lead back to you)

# [Verse 2]
# Go ahead and say it
# What you want, I'm right here waitin'
# 'Cause we can waste away the nights with all
# The things we hold inside until
# We go ahead and say them

# [Pre-Chorus]
# So maybe I should put my heart out on the table
# And fuck it if it breaks
# And maybe I've been hiding from what I'm afraid of
# But I don't wanna wait

# [Chorus]
# No, I don't wanna ooh, ooh-ooh-ooh
# I'm always running so I can't get close to you
# But we don't got a lot of time to lose
# And all that I want is to finally be honest
# Yeah, ooh, ooh-ooh-ooh
# I'm always running but my feet lead back to you
# [Drop]
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (Back to you)
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (I'm always running but my feet lead back to you)
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (Back to you)
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (I'm always running but my feet lead back to you)

# [Outro]
# (Ooh-ooh-ooh, ooh-ooh-ooh)
# (Back to you)
# (Ooh-ooh-ooh, ooh-ooh-ooh)

ipn, sn = map(int, input().split())
arr = list(map(int, input().split()))
lo = min(arr)
hi = sum(arr)
final = hi
while(lo < hi):
    mid = lo + (hi-lo)//2
    counter = 0
    ans = 1
    #print("The current mid is: " + str(mid))
    for i in arr:
        if (counter+i <= mid):
            counter += i
        else:
            counter = i
            ans+=1
    if ans <= sn:
        hi = mid
    else:
        lo = mid+1
print(lo)

