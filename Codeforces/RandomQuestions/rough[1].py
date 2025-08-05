def main():
    n = input().strip()
    n_int = int(n)
    results = []
    
    for a in range(1, 10001):
        for b in range(max(1, len(n)*a-5), len(n)*a):
            x = n_int * a - b
            y = str(n * a)
            y = y[:len(y)-b]
            if str(x) == y:
                results.append((a, b))
    
    print(len(results))
    for a, b in results:
        print(a, b)

t = int(input().strip())
for _ in range(t):
    main()
