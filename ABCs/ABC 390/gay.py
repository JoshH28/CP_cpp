def count_distinct_xor_values(N, A):
    from itertools import combinations
    possible_values = set()
    for r in range(1, N + 1):
        for subset in combinations(A, r):
            possible_values.add(sum(subset))
    return len(possible_values)

N = int(input())
A = list(map(int, input().split()))
print(count_distinct_xor_values(N, A))
