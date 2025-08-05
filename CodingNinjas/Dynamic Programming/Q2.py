def max_revenue(M, sites, revenue):
    n = len(sites)
    sites.sort()
    dp = [0] * (n + 1)

    for i in range(0, n):
        dp[i+1] = revenue[i]  # Initialize dp[i] with revenue[i]
        for j in range(0, i):
            if sites[i] - sites[j] > 5:
                dp[i+1] = max(dp[i+1], dp[j+1] + revenue[i])
1
    return dp[n]

# Example usage:
M = 20
sites = [6, 7, 12, 14, 18]
revenue = [5, 6, 5, 1, 2]
max_total_revenue = max_revenue(M, sites, revenue)
print("Maximum total revenue achievable:", max_total_revenue)
