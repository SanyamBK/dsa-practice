def min_islands(t, test_cases):
    results = []
    for test in test_cases:
        n, k = test
        if k >= n - 1:
            results.append(n - 1)
        else:
            results.append(1)
    return results

# Input parsing
t = int(input().strip())
test_cases = []
for _ in range(t):
    n, k = map(int, input().strip().split())
    test_cases.append((n, k))

# Compute and output results
for result in min_islands(t, test_cases):
    print(result)
