# In the town full of fancy cars and
# Crowded bars and supermodels
# Looks exactly the way it did inside my head
# When I dreamed about it
# All the things I could live without
# I need 'em now 'cause they're all around me
# Only thing that I can't afford is to lose myself
# Tryna be somebody, somebody
# You should've known better
# Than to listen to your heart again
# People change with the weather
# (You know, just know what I like)
# I don't really like anybody
# So don't tell me I'm like anybody else
# You put it back together
# Don't let it fall apart again
# People change with the weather
# In the town full of fancy cars and
# Crowded bars and supermodels
# Looks exactly the way it did inside my head
# When I dreamed about it
# All the things I could live without
# I need 'em now 'cause they're all around me
# Only thing that I can't afford is to lose myself
# Tryna be somebody, somebody
# Somebody
# Somebody
# (You know, just know what I like)
# Somebody
# In my head I knew better (In my head I knew better)
# I won't blame it on my faults again
# I know I should forget her
# (You know, just know what I like)
# I don't really like anybody
# So don't tell me I'm like anybody else
# In the town full of fancy cars and
# Crowded bars and supermodels
# Looks exactly the way it did inside my head
# When I dreamed about it
# All the things I could live without
# I need 'em now 'cause they're all around me
# Only thing that I can't afford is to lose myself
# Tryna be somebody, somebody
# Somebody, somebody
# Somebody, somebody
# (You know, just know what I like)
# Somebody, somebody
# Somebody, somebody
# (You know, just know what I like)
# 'Cause I don't really like anybody
# So don't tell me I'm like anybody
# 'Cause I don't really like anybody
# So don't tell me I'm like anybody
# In the town full of fancy cars and
# Crowded bars and supermodels
# Looks exactly the way it did inside my head
# When I dreamed about it
# All the things I could live without
# I need 'em now 'cause they're all around me
# Only thing that I can't afford is to lose myself
# Tryna be somebody, somebody
# Somebody, somebody
# Somebody, somebody
# (You know, just know what I like)
# Somebody, somebody
# Somebody, somebody
# (You know, just know what I like)
# Lose myself tryna please somebody
# Lose myself tryna please somebody
def check(first, second):
  if not (first[0] < second[0] < first[3] or second[0] < first[0] < second[3]):
    return "No"
  if not (first[1] < second[1] < first[4] or second[1] < first[1] < second[4]):
    return "No"
  if not (first[2] < second[2] < first[5] or second[2] < first[2] < second[5]):
    return "No"
  return "Yes"
  
  
first = list(map(int, input().split()))
second = list(map(int, input().split()))
print(check(first, second))