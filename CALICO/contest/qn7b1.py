# I'm in the thick of it, everybody knows
# They know me where it snows, I skied in and they froze
# I don't know no nothin' 'bout no ice, I'm just cold
# Forty somethin' milli' subs or so, I've been told
# I'm in my prime and this ain't even final form
# They knocked me down, but still, my feet, they find the floor
# I went from living rooms straight out to sold-out tours
# Life's a fight, but trust, I'm ready for the war
# Woah-oh-oh
# This is how the story goes
# Woah-oh-oh
# I guess this is how the story goes
# I'm in the thick of it, everybody knows
# They know me where it snows, I skied in and they froze
# I don't know no nothin' 'bout no ice, I'm just cold
# Forty somethin' milli' subs or so, I've been told
# From the screen to the ring, to the pen, to the king
# Where's my crown? That's my bling
# Always drama when I ring
# See, I believe that if I see it in my heart
# Smash through the ceiling 'cause I'm reachin' for the stars
# Woah-oh-oh
# This is how the story goes
# Woah-oh-oh
# I guess this is how the story goes
# I'm in the thick of it, everybody knows
# They know me where it snows, I skied in and they froze (woo)
# I don't know no nothin' 'bout no ice, I'm just cold
# Forty somethin' milli' subs or so, I've been told
# Highway to heaven, I'm just cruisin' by my lone'
# They cast me out, left me for dead, them people cold
# My faith in God, mind in the sun, I'm 'bout to sow (yeah)
# My life is hard, I took the wheel, I cracked the code (yeah-yeah, woah-oh-oh)
# Ain't nobody gon' save you, man, this life will break you (yeah, woah-oh-oh)
# In the thick of it, this is how the story goes
# I'm in the thick of it, everybody knows
# They know me where it snows, I skied in and they froze
# I don't know no nothin' 'bout no ice, I'm just cold
# Forty somethin' milli' subs or so, I've been told
# I'm in the thick of it, everybody knows (everybody knows)
# They know me where it snows, I skied in and they froze (yeah)
# I don't know no nothin' 'bout no ice, I'm just cold
# Forty somethin' milli' subs or so, I've been told (ooh-ooh)
# Woah-oh-oh (nah-nah-nah-nah, ayy, ayy)
# This is how the story goes (nah, nah)
# Woah-oh-oh
# I guess this is how the story goes
from typing import List, Set, Tuple
from collections import deque

def count_islands(grid: List[List[int]], n: int, m: int, height: int) -> int:
    visited = [[False] * m for _ in range(n)]
    islands = 0
    def is_valid(x: int, y: int) -> bool:
        return 0 <= x < n and 0 <= y < m
    def bfs(start_x: int, start_y: int) -> bool:
        if visited[start_x][start_y]:
            return False
        queue = deque([(start_x, start_y)])
        visited[start_x][start_y] = True
        component = [(start_x, start_y)]
        while queue:
            x, y = queue.popleft()
            for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                new_x, new_y = x + dx, y + dy
                if (is_valid(new_x, new_y) and 
                    not visited[new_x][new_y] and 
                    grid[new_x][new_y] >= height):
                    queue.append((new_x, new_y))
                    visited[new_x][new_y] = True
                    component.append((new_x, new_y))
        for x, y in component:
            for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                new_x, new_y = x + dx, y + dy
                if is_valid(new_x, new_y):
                    if not visited[new_x][new_y] and grid[new_x][new_y] >= height:
                        return False
        return True
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and grid[i][j] >= height:
                if bfs(i, j):
                    islands += 1
    return islands

def binary_search_optimal_height(grid: List[List[int]], n: int, m: int) -> Tuple[int, int]:
    def get_island_count(h: int) -> int:
        return count_islands(grid, n, m, h)
    min_height = 0
    max_height = max(max(row) for row in grid) + 1
    left, right = min_height, max_height
    while right - left > 2:
        third = (right - left) // 3
        mid1 = left + third
        mid2 = right - third
        count1 = get_island_count(mid1)
        count2 = get_island_count(mid2)
        if count1 < count2:
            left = mid1
        else:
            right = mid2
    max_islands = 0
    optimal_height = left
    for h in range(left, right + 1):
        islands = get_island_count(h)
        if islands > max_islands:
            max_islands = islands
            optimal_height = h
    
    return max_islands, optimal_height

def solve_test_case() -> int:
    n, m = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]
    max_islands, _ = binary_search_optimal_height(grid, n, m)
    return max_islands

def main():
    t = int(input())
    for _ in range(t):
        print(solve_test_case())

main()