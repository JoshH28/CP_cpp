# [Verse 1]
# I took our love and I put it on ice
# This bed is cold and it don't feel right
# Ain't nobody else could love me like that
# You love me like that, no
# You give me space and I'll give you the sky
# Yeah, you got me thinkin' we could try, try, try
# Ain't nobody else could love me like that
# You love me like that

# [Pre-Chorus]
# When I said it's over
# Thought I really meant that
# Now, I'm wantin' you back
# So just hold me closer
# Ain't nobody like us
# Now, I know

# [Chorus]
# So come on and love me like you did before
# Tell me I'm worth fightin' for
# Show me that there's somethin' more
# We can do better
# Brick by brick, we built these walls
# But tonight, we'll watch them fall, so
# Love me like you did before
# We can do better, we can do better

# [Drop]
# We can do better, we can do better
# We can do better, we can do better

# [Verse 2]
# So take this bed and set it on fire
# Only you know my dark desires
# Ain't nobody else could love me like that
# You love me like that

# [Pre-Chorus]
# When I said it's over
# Thought I really meant that
# Now, I'm wantin' you back
# So just hold me closer
# Ain't nobody like us
# Now, I know

# [Chorus]
# So come on and love me like you did before
# Tell me I'm worth fightin' for
# Show me that there's somethin' more
# We can do better
# Brick by brick, we built these walls
# But tonight, we'll watch them fall, so
# Love me like you did before
# We can do better, we can do better
# [Drop]
# We can do better, we can do better
# We can do better, we can do better

# [Chorus]
# Love me like you did before
# Tell me I'm worth fightin' for
# Show me that there's somethin' more
# We can do better
# Brick by brick, we built these walls
# But tonight, we'll watch them fall, so
# Love me like you did before
# We can do better, we can do better

n = int(input())
string = input()
dic = {}
for i in range(ord('a'), ord('z')+1):
    dic[chr(i)] = 0
for i in string:
    dic[i] += 1
for i in range(ord('a'), ord('z')+1, 1):
    print(chr(i), dic[chr(i)])