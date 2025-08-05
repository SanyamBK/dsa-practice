def max_total_score(Score, Wait):
    n = len(Score)
    dp = [0] * (n + 1)

    for i in range(0, n):
        dp[i+1] = max(dp[i], Score[i] + (dp[i - Wait[i]] if i - Wait[i] > 0 else 0))

    return dp[n]

# Example usage:
Score = [3, 2, 5, 4, 7]
Wait = [1, 2, 1, 2, 1]
max_score = max_total_score(Score, Wait)
print("Maximum total score achievable:", max_score)
