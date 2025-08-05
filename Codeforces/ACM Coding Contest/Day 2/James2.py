def testCase():
    n, k = map(int, input().split())
    s1 = list(map(int, input().split()))
    s2 = list(map(int, input().split()))

    while k > 0:
        max_diff = 0
        ind1 = -1
        ind2 = 0
        for i in range(n-1):
            diff = abs(s1[i] - s1[i+1])
            if diff > max_diff:
                ind1, ind2 = i, i+1
        

        diff1 = abs(s1[ind1] - s2[ind2])
        diff2 = abs(s1[ind2] - s1[ind1])

        sidediff1 = abs(s1[ind1] - s1[ind1-1])
        sidediff2 = float('inf')
        if ind2 < n - 1:
            sidediff2 = abs(s1[ind2] - s1[ind1+2])

        if diff1 < max_diff and diff2 > max_diff:
            s1[ind2], s2[ind2] = s2[ind2], s1[ind2]
        
        elif diff2 < max_diff and diff1 < max_diff:
            s1[ind1], s2[ind1] = s2[ind1], s1[ind1]

        elif diff1 < max_diff and diff2 < max_diff:
            if diff1 < diff2:
                if sidediff1 < sidediff2:
                    s1[ind2], s2[ind2] = s2[ind2], s1[ind2]
                else:
                    s1[ind1], s2[ind1] = s2[ind1], s1[ind1]

            elif diff2 < diff1:
                if sidediff2 > sidediff1:
                    s1[ind1], s2[ind1] = s2[ind1], s1[ind1]
                else:
                    s1[ind2], s2[ind2] = s2[ind2], s1[ind2]
            
        k -= 1

    max_diff = max(abs(s1[i] - s1[i+1]) for i in range(n-1))
    print(max_diff)



t = int(input())
for _ in range(t):
    testCase()
