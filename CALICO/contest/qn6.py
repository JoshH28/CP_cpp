from math import gcd
from typing import List, Tuple

def generate_visible_houses(limit: int) -> List[Tuple[int, int]]:
    """
    Generate coordinates of visible houses from (0,0) up to a certain Manhattan distance limit.
    Returns list of (x,y) coordinates sorted by Manhattan distance and x-coordinate.
    """
    houses = []
    
    # For each x,y within the limit of Manhattan distance
    for manhattan_dist in range(1, limit + 1):
        for x in range(0, manhattan_dist + 1):
            y = manhattan_dist - x
            if y == 0:  # Handle x-axis points
                if x > 0:  # Exclude origin
                    houses.append((x, y))
            elif x == 0:  # Handle y-axis points
                houses.append((x, y))
            else:
                # Only add point if it's visible (gcd of coordinates is 1)
                if gcd(x, y) == 1:
                    houses.append((x, y))
    
    # Sort houses by Manhattan distance, then by x coordinate
    houses.sort(key=lambda p: (p[0] + p[1], p[0]))
    return houses

def get_nth_house_slow(N: int) -> Tuple[int, int]:
    """
    Get the coordinates of the Nth house (slower but works for small N).
    """
    # Generate enough houses to definitely include the Nth one
    # We use 2*N as a safe upper bound for small N
    houses = generate_visible_houses(2 * N)
    return houses[N - 1]

def count_visible_houses_up_to_distance(d: int) -> int:
    """
    Count number of visible houses with Manhattan distance <= d.
    Uses the fact that visible houses are those with coprime coordinates.
    """
    count = 0
    for x in range(d + 1):
        for y in range(d + 1 - x):
            if x == 0 and y == 0:
                continue
            if x == 0 or y == 0:
                count += 1
            elif gcd(x, y) == 1:
                count += 1
    return count

def binary_search_distance(N: int) -> int:
    """
    Binary search to find the Manhattan distance that contains the Nth house.
    """
    left, right = 1, N
    while left < right:
        mid = (left + right) // 2
        count = count_visible_houses_up_to_distance(mid)
        if count < N:
            left = mid + 1
        else:
            right = mid
    return left

def get_nth_house_fast(N: int) -> Tuple[int, int]:
    """
    Get the coordinates of the Nth house efficiently for large N.
    """
    # Find the Manhattan distance that contains our target house
    distance = binary_search_distance(N)
    
    # Generate houses up to this distance and get the Nth one
    houses = generate_visible_houses(distance)
    return houses[N - 1]

def solve(N: int) -> Tuple[int, int]:
    """
    Main solver function that chooses the appropriate method based on N.
    """
    if N <= 100:
        return get_nth_house_slow(N)
    return get_nth_house_fast(N)

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        x, y = solve(N)
        print(f"{x} {y}")

main()