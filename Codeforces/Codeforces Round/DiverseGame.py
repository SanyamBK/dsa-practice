def main():
    n, m = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(n)]
    if n == 1 and m == 1:
        print(-1)
        return
    else:
        if m > 1:
            for i in range(n):
                first = matrix[i][0]
                for j in range(0, m-1):
                    matrix[i][j] = matrix[i][j+1]
                matrix[i][m-1] = first
                
        if n > 1:
            first = matrix[0]
            for i in range(0, n-1):
                matrix[i] = matrix[i+1]
            matrix[n-1] = first
    
    for i in range(n):
        for j in range(m):
            print(matrix[i][j], end=' ')
        print()
    return

t = int(input())
for i in range(t):
    main()  