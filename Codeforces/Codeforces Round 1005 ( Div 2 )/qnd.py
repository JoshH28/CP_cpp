import sys
import bisect

def solve():
    # Read number of test cases
    t = int(sys.stdin.readline().strip())

    results = []
    
    for _ in range(t):
        # Read n (number of slimes) and q (number of queries)
        n, q = map(int, sys.stdin.readline().split())

        # Read weights of slimes
        weights = list(map(int, sys.stdin.readline().split()))

        # **Step 1: Precompute the effective surviving slimes using a monotonic decreasing stack**
        stack = []  # Stores (weight, cumulative count of slimes eaten before)
        eaten_count = []  # Number of slimes eaten before each element

        count = 0  # Tracks how many slimes have been eaten in total
        for w in weights:
            while stack and stack[-1][0] <= w:
                prev_w, prev_count = stack.pop()
                count += 1  # This slime gets eaten
                w ^= prev_w  # New weight after eating
            
            stack.append((w, count))
            eaten_count.append(count)

        # Extract the weights and the counts
        surviving_weights = [w[0] for w in stack]
        surviving_eaten = [w[1] for w in stack]

        # **Step 2: Answer queries in O(log n) using binary search**
        for _ in range(q):
            x = int(sys.stdin.readline().strip())

            # Use binary search to find the stopping point
            pos = bisect.bisect_right(surviving_weights, x)
            
            if pos == 0:
                results.append("0")  # If x is the smallest, no slimes eaten
            else:
                results.append(str(surviving_eaten[pos - 1]))

    # Print all results at once to optimize I/O performance
    sys.stdout.write("\n".join(results) + "\n")

solve()