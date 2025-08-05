def main():
    n = int(input())
    a = list(map(int, input().split()))
    
    freq = {}
    for value in a:
        if value in freq:
            freq[value] += 1
        else:
            freq[value] = 1

    counts = list(freq.values())
    counts.sort()

    n = len(counts)
    dp = [float('inf')] * (n + 1)
    dp[0] = 0

    for i in range(1, n + 1):
        ndp = dp.copy()
        for k in range(1, i + 1):
            x = dp[k - 1] + counts[i - 1]
            if x <= i - k:
                ndp[k] = min(ndp[k], x)
        dp = ndp

    ans = n
    while dp[ans] >= float('inf'):
        ans -= 1
    print(n - ans)

# Reading number of test cases
t = int(input())
for _ in range(t):
    main()
