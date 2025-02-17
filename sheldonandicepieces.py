# [Verse 1]
# In your eyes, there's a heavy blue
# One to love, and one to lose
# Sweet divine, a heavy truth
# Water or wine, don't make me choose

# [Pre-Chorus]
# I wanna feel the way that we did that summer night, night (Ah)
# Drunk on a feelin', alone with the stars in the sky

# [Chorus]
# I've been runnin' through the jungle
# I've been runnin' with the wolves
# To get to you, to get to you
# I've been down the darkest alleys
# Saw the dark side of the moon
# To get to you, to get to you
# I've looked for love in every stranger
# Took too much to ease the anger
# All for you, yeah, all for you
# I've been runnin' through the jungle
# I've been cryin' with the wolves
# To get to you, to get to you, to get to you

# [Drop]
# Ah-ah, ah-ah
# Ah-ah, to get to you
# Ah-ah, ah-ah
# Ah-ah, to get to you

# [Verse 2]
# Your fingertips trace my skin
# To places I have never been
# Blindly, I am following
# Break down these walls and come on in

# [Pre-Chorus]
# I wanna feel the way that we did that summer night, night (Ah)
# Drunk on a feelin', alone with the stars in the sky

# [Chorus]
# I've been runnin' through the jungle
# I've been runnin' with the wolves
# To get to you, to get to you
# I've been down the darkest alleys
# Saw the dark side of the moon
# To get to you, to get to you
# I've looked for love in every stranger
# Took too much to ease the anger
# All for you, yeah, all for you
# I've been runnin' through the jungle
# I've been cryin' with the wolves
# To get to you, to get to you, to get to you

# [Drop]
# Ah-ah, ah-ah
# Ah-ah, to get to you
# Ah-ah, ah-ah
# Ah-ah, to get to you
# [Chorus]
# I've been runnin' through the jungle
# I've been runnin' with the wolves
# To get to you, to get to you
# I've been down the darkest alleys
# Saw the dark side of the moon
# To get to you, to get to you
# I've looked for love in every stranger
# Took too much to ease the anger
# All for you, yeah, all for you
# I've been runnin' through the jungle
# I've been cryin' with the wolves
# To get to you, to get to you, to get to you
s1 = input()
s2 = input()
yes, gay = {}, {}
for i in s1:
  if (i == '5'):
    i = '2'
  elif (i == '9'):
    i = '6'
  if (i not in yes.keys()):
    yes[i] = 1
  else:
    yes[i] += 1
for i in s2:
  if (i == '5'):
    i = '2'
  elif (i == '9'):
    i = '6'
  if (i not in gay.keys()):
    gay[i] = 1
  else:
    gay[i] += 1
lo, hi, ans = 0, 10**9, -1 
while (lo <= hi):
  mid, flag = (lo+hi)//2, 1
  for i in yes.keys():
    if (yes[i]*mid > gay[i]):
      flag = 0
  if (flag):
    ans = max(ans, mid)
    lo = mid+1
  else:
    hi = mid-1
print(ans)
    
    

    
