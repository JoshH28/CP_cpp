def solve_test_case(n, h, d, s, p):
    travel_time = d / s
    damage_during_travel = travel_time * p
    if damage_during_travel <= n:
        return travel_time
    if h <= p:
        return -1.0
    healing_time_needed = (p * (d/s) - n) / (h - p)
    if healing_time_needed < 0:
        return travel_time
        
    return healing_time_needed + travel_time
tc = int(input())
for _ in range(tc):
    n, h, d, s, p = map(int, input().split())
    result = solve_test_case(n, h, d, s, p)
    print(f"{result:.1f}")