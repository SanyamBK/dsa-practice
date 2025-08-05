def maximumJob(A, B, n):
    # Initialize cost for the first two minutes
    cost = [[0, 0] for _ in range(n + 1)]
    cost[1][0] = A[0]
    cost[1][1] = B[0]
    
    for i in range(2, n + 1):
        # Calculate cost for running on machine A
        cost[i][0] = max(A[i - 1] + cost[i - 1][0], A[i - 1] + cost[i - 2][1])
        # Calculate cost for running on machine B
        cost[i][1] = max(B[i - 1] + cost[i - 1][1], B[i - 1] + cost[i - 2][0])
    
    # Return the maximum cost from both machines
    return max(cost[n][0], cost[n][1])

# Example usage
A = [5, 3, 4, 8, 6]
B = [2, 7, 1, 5, 3]
n = len(A)
print("Maximum job cost:", maximumJob(A, B, n))
