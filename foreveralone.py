# [Intro]
# Don't go

# [Verse 1]
# Lose it all and find
# That you're slipping through my fingers
# And the pain, it stays and lingers
# Try to stay alive, but I fear I'm losing patience this time (This time)

# [Pre-Chorus]
# All of the things you said we'd do
# They're just overused
# All of the things you said we'd try
# They just passed us by
# I'm getting sick of saving lives and leaving mine to dry
# So I picked up the pace
# Left you, I don't need you, babe

# [Chorus]
# Why does the world keep spinning 'round
# When all I did was hold you down?
# Feels like I'm losing patience when you keep me waiting
# Why does the world keep spinning 'round
# When all I did was hold you down?
# It's so hard to save you, whеn I needed saving

# [Drop]
# When I needed saving
# And thе world keeps spinning 'round
# I tried to hold you down

# [Verse 2]
# Ooh, I love you now but time's running out and I'm losing you
# It's like our love was fine
# But we lost our minds and feelings
# And you can blame me for the reasons

# [Pre-Chorus 2]
# All of the times we tried to fix us left me compromised
# You told me to leave you so I did and now our love has died
# I'm getting sick of saving lives and leaving mine to dry
# So I picked up the pace
# Left you, I don't need you, babe

# [Chorus]
# Why does the world keep spinning 'round
# When all I did was hold you down?
# Feels like I'm losing patience when you keep me waiting
# Why does the world keep spinning 'round
# When all I did was hold you down?
# But it's hard to save you, when I needed saving
# [Drop]
# Saving
# And the world keeps spinning 'round
# I tried to hold you down

# [Outro]
# (Mmm)
# Why does the world keep spinning round
# (Mmm)
# When all I did was hold you down?
# (Mmm)
# Why does the world keep spinning round
# (Mmm)
# When all I did was hold you down?
n, qn = map(int, input().split())
count = n
halp = {} # i hope this is a dictionary
for i in range(qn):
    c1, c2 = map(int, input().split())
    if (c1 == c2):
        continue
    try: 
        assert halp[c1] == 1
    except:
        count-=1
        halp[c1] = 1
    try: 
        assert halp[c2] == 1
    except:
        count-=1
        halp[c2] = 1
print(count)
