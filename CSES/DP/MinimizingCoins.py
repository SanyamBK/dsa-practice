
def soln(n, x, coins, dp):
    if x == 0:
        return 0
    if x < 0:
        return float('inf')
    if n == 0:
        return float('inf')
    if dp[n][x] != -1:
        return dp[n][x]
    dp[n][x] = min(1 + soln(n, x - coins[n - 1], coins, dp), soln(n - 1, x, coins, dp))
    return dp[n][x]
    


n, x  = map(int, input().split())
coins = list(map(int, input().split()))

dp = [[-1 for i in range(x + 1)] for j in range(n + 1)]
ans = soln(n, x, coins, dp)
if ans == float('inf'):
    print(-1)
else:
    print(ans)
