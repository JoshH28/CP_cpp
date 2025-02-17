def min_operations_to_7(n):
    if '7' in str(n):
        return 0  # Already contains '7'

    step = 0
    nine = 9  # Start by adding 9
    while True:
        n += nine
        step += 1
        if '7' in str(n):
            return step
        nine = nine * 10 + 9  # Increase to 99, 999, etc.

def solve():
    t = int(input())  # Number of test cases
    results = []
    for _ in range(t):
        n = int(input())
        results.append(str(min_operations_to_7(n)))
    print("\n".join(results))
solve()
# Example usage:
# Input:
# 3
# 80
# 25
# 100
# Output:
# 1
# 2
# 1
