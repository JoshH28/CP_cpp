from typing import List, Set
from collections import deque

def count_islands(grid: List[List[int]], n: int, m: int, height: int) -> int:
    visited = [[False] * m for _ in range(n)]
    islands = 0
    
    def is_valid(x: int, y: int) -> bool:
        return 0 <= x < n and 0 <= y < m
    
    def is_surrounded_by_water(x: int, y: int) -> bool:
        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            new_x, new_y = x + dx, y + dy
            if is_valid(new_x, new_y) and grid[new_x][new_y] >= height:
                return False
        return True
    
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
            has_higher_neighbor = False
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

def solve_test_case() -> int:
    n, m = map(int, input().split())
    grid = []
    heights = set()
    for _ in range(n):
        row = list(map(int, input().split()))
        grid.append(row)
        heights.update(row)
    heights.add(0)
    heights.add(max(max(row) for row in grid) + 1)
    max_islands = 0
    for h in sorted(heights):
        islands = count_islands(grid, n, m, h)
        max_islands = max(max_islands, islands)
    return max_islands

def main():
    t = int(input())
    for _ in range(t):
        print(solve_test_case())

main()