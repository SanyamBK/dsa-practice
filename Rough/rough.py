def is_possible(matrix, val):
    n, m = len(matrix), len(matrix[0])
    bitmasks = []

    for row in matrix:
        mask = 0
        for j in range(m):
            if row[j] >= val:
                mask |= (1 << j)
        bitmasks.append(mask)

    full_mask = (1 << m) - 1

    # Check all pairs of rows
    for i in range(len(bitmasks)):
        for j in range(len(bitmasks)):
            if (bitmasks[i] | bitmasks[j]) == full_mask:
                return True
    return False

def maximize_min_of_column_max(matrix):
    unique_vals = sorted(set(val for row in matrix for val in row))
    low, high = 0, len(unique_vals) - 1
    answer = unique_vals[low]

    while low <= high:
        mid = (low + high) // 2
        if is_possible(matrix, unique_vals[mid]):
            answer = unique_vals[mid]
            low = mid + 1
        else:
            high = mid - 1

    return answer

# Test case
matrix = [
    [1, 3, 1],
    [3, 1, 1],
    [1, 2, 2],
    [1, 1, 3]
]

print(maximize_min_of_column_max(matrix))  # ✅ Output: 2
