def total_xor_sum(arr):
    n = len(arr)
    total_sum = 0
    # Iterate through each element
    for i in range(n):
        # Compute the number of subarrays including arr[i]
        left = i + 1  # Subarrays that can start at or before i
        right = n - i  # Subarrays that can end at or after i
        # If a number is included in an odd number of subarrays in XOR summation, it contributes to the final XOR
        if (left * right) % 2 == 1:
            total_sum ^= arr[i]
    return total_sum

n = int(input().strip())
arr = list(map(int, input().strip().split()))
print(total_xor_sum(arr))
