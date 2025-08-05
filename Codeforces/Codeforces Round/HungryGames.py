def toxicity(n, x, a, g):
    if n == 0:
        return int(a[0] > x)
    notTake = toxicity(n-1, x, a, g)
    take = 0
    g = g + a[n]
    if (g) > x:
        take = toxicity(n-1, x, a, 0)
    else:
        take = 1 + toxicity(n-1, x, a, g)

    return take + notTake

def main():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    ans = toxicity(n-1, x, a, 0)
    print(ans)
    
t = int(input())
for i in range(t):
    main()