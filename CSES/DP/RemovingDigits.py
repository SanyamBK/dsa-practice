'''
n = int(input())
n_str = list(str(n))
cnt = 0 
while (n >= 0):
    if n == 0:
        print(cnt)
        break
    n = n - int(max(n_str))
    n_str = list(str(n))
    cnt += 1
'''
# 2nd solution
n = int(input())
dp = [1e9] * (n+1)
dp[0] = 0
for i in range(1, n+1):
    for j in str(i):
        if j != '0':
            dp[i] = min(dp[i], dp[i - int(j)] + 1)
        
        
print(dp[n])