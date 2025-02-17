def min_moves(test_cases):
    results = []
    for case in test_cases:
        n, s = case
        t = ""  # Initially empty
        moves = 0

        while True:
            # Check if s contains only '0's and t contains only '1's
            if all(c == '0' for c in s) and all(c == '1' for c in t):
                break

            # Find the longest suffix of s that can be moved to t
            # We want to move the longest suffix of s that contains '1's
            move_from_s = False
            for i in range(n - 1, -1, -1):
                if s[i] == '1':
                    move_from_s = True
                    break

            if move_from_s:
                # Move the suffix from s to t
                suffix = s[i:]
                s = s[:i]
                t += suffix
                moves += 1
            else:
                # Find the longest suffix of t that can be moved to s
                # We want to move the longest suffix of t that contains '0's
                move_from_t = False
                for j in range(len(t) - 1, -1, -1):
                    if t[j] == '0':
                        move_from_t = True
                        break

                if move_from_t:
                    # Move the suffix from t to s
                    suffix = t[j:]
                    t = t[:j]
                    s += suffix
                    moves += 1
                else:
                    # No more moves needed
                    break

        results.append(moves)
    return results

# Read input
t = int(input())  # Number of test cases
test_cases = []
for _ in range(t):
    n = int(input())  # Length of the string s
    s = input().strip()  # Binary string s
    test_cases.append((n, s))

# Compute results
results = min_moves(test_cases)

# Output results
for result in results:
    print(result)