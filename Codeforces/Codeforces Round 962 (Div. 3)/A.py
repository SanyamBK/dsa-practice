def main():
    n, k = map(int, input().split())
    a = [[int(x) for x in input().split()] for _ in range(n)]
    # print(a)
    for i in range(n):
        for j in range(n):
            print(a[i][j], end=' ')
        print()
        
        
t = int(input())
for _ in range(t):
    main()