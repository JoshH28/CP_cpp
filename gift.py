# [Verse 1]
# Me and you, you and me, was a dream at first
# I got lost, in your world, in your universe
# I never thought our love would ever end
# I messed up, made it worse, pushed you away
# All that fighting and pain, 'til you left one day
# Wish I could take back all those things I said

# [Chorus]
# I can't deny that I miss you and I know that you miss me too
# So let's get over our issues and go back to me plus you
# I know that things weren't perfect but I think it's worth it
# Nobody knows you like I do
# I can't deny that I miss you, I miss you
# Let's go back to me plus you
# I can't deny that I miss you and I know that you miss me too
# So let's get over our issues and go back to me plus you
# I know that things wеren't perfect but I think it's worth it
# Nobody knows you likе I do
# I can't deny that I miss you, I miss you
# Let's go back to me plus you

# [Verse 2]
# I'm a mess, I'm a wreck, when I see your face
# And I know that you're feeling exactly the same
# Let's stop pretending we should stay apart
# Tried to meet someone new but they can't compare
# And I know that I'm being a bit unfair
# But you're the only one that's in my heart

# [Chorus]
# I can't deny that I miss you and I know that you miss me too
# So let's get over our issues and go back to me plus you
# I know that things weren't perfect but I think it's worth it
# Nobody knows you like I do
# I can't deny that I miss you, I miss you
# Let's go back to me plus you
# I can't deny that I miss you and I know that you miss me too
# So let's get over our issues and go back to me plus you
# I know that things weren't perfect but I think it's worth it
# Nobody knows you like I do
# I can't deny that I miss you, I miss you
# Let's go back to me plus you
n, k = map(int, input().split())
giftN = 0
prev = int(input())
for i in range(n-1):
    curr = int(input())
    if (curr+100 <= prev):
        giftN+=1
        prev = curr
    else:
        prev = curr

print(giftN)
