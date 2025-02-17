from collections import deque
from typing import List, Tuple

def solve_madeline_path(grid: List[str], N: int, M: int, K: int) -> int:
    start_pos = end_pos = None
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 'S':
                start_pos = (i, j)
            elif grid[i][j] == 'E':
                end_pos = (i, j)
    visited = [[[False]*2 for _ in range(M)] for _ in range(N)]
    visited[start_pos[0]][start_pos[1]][1] = True
    directions = ((-1, 0), (0, 1), (1, 0), (0, -1))
    def is_valid(row: int, col: int) -> bool:
        return 0 <= row < N and 0 <= col < M and grid[row][col] != '#'
    
    def try_dash(row: int, col: int, dir_row: int, dir_col: int) -> Tuple[int, int, bool]:
        new_row, new_col = row, col
        found_crystal = False
        dr = dir_row * K
        dc = dir_col * K
        target_row = row + dr
        target_col = col + dc
        left_steps = 0
        right_steps = K
        
        while left_steps < right_steps:
            mid_steps = (left_steps + right_steps + 1) >> 1
            test_row = row + dir_row * mid_steps
            test_col = col + dir_col * mid_steps
            
            if is_valid(test_row, test_col):
                left_steps = mid_steps
            else:
                right_steps = mid_steps - 1
        
        if left_steps > 0:
            new_row = row + dir_row * left_steps
            new_col = col + dir_col * left_steps
            for step in range(1, left_steps + 1):
                check_row = row + dir_row * step
                check_col = col + dir_col * step
                if grid[check_row][check_col] == '*':
                    found_crystal = True
                    break
                    
        return new_row, new_col, found_crystal
    queue = [(start_pos[0], start_pos[1], True, 0)]
    qi = 0 
    while qi < len(queue):
        row, col, is_red, moves = queue[qi]
        qi += 1
        if (row, col) == end_pos:
            return moves
        for dir_row, dir_col in directions:
            new_row = row + dir_row
            new_col = col + dir_col
            if not is_valid(new_row, new_col):
                continue
            new_is_red = 1 if (is_red or grid[new_row][new_col] == '*') else 0
            if not visited[new_row][new_col][new_is_red]:
                visited[new_row][new_col][new_is_red] = True
                queue.append((new_row, new_col, new_is_red, moves + 1))
        if is_red:
            for dir_row, dir_col in directions:
                new_row, new_col, found_crystal = try_dash(row, col, dir_row, dir_col)
                
                if (new_row, new_col) != (row, col):
                    new_is_red = 1 if found_crystal else 0
                    
                    if not visited[new_row][new_col][new_is_red]:
                        visited[new_row][new_col][new_is_red] = True
                        queue.append((new_row, new_col, new_is_red, moves + 1))
    
    return -1

def main():
    import sys
    input = sys.stdin.readline
    
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        grid = [input().strip() for _ in range(N)]
        print(solve_madeline_path(grid, N, M, K))

main()