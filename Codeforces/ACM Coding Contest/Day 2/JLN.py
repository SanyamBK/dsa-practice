def testCase():
    n, k = map(int, input().split())
    s1 = list(map(int, input().split()))
    s2 = list(map(int, input().split()))

    difflist = []
    for j in range(n-1):
        difflist.append((abs(s1[j] - s1[j+1]), j))
    
    difflist.sort(key=lambda v:v[0])
    difflist.reverse()
    
    while k > 0:
        
        pair = difflist.pop(0)
        maxdiff = pair[0]
        ind = pair[1]

        diff1 = abs(s1[ind] - s2[ind+1])
        diff2 = abs(s1[ind+1] - s2[ind])
        ind1 = ind + 1

        if ind > 0 and ind1 < n-1 and diff1 < maxdiff and diff2 < maxdiff:
            sidediff1 = abs(s1[ind1] - s1[ind1+1])
            sidediff2 = abs(s1[ind-1] - s1[ind])
            if sidediff1 > sidediff2:
                newdiff = diff1
                s1[ind1], s2[ind1] = s2[ind1], s1[ind1]
                difflist.append((newdiff, ind))
                difflist = list(filter(lambda t: t[1] != ind1, difflist))
                difflist.append((abs(s1[ind1] - s1[ind1+1]), ind1))

            else:
                newdiff = diff2
                s1[ind], s2[ind] = s2[ind], s1[ind]
                difflist.append((newdiff, ind))
                difflist = list(filter(lambda t: t[1] != ind-1, difflist))
                difflist.append((abs(s1[ind] - s1[ind-1]), ind-1))
                
            k -= 1
            difflist.sort(key=lambda v:v[0])
            difflist.reverse()


        
        elif diff1 > maxdiff and diff2 < maxdiff:
            newdiff = diff2
            s1[ind], s2[ind] = s2[ind], s1[ind]
            difflist.append((newdiff, ind))
            if (ind - 1 > 0):
                difflist = list(filter(lambda t: t[1] != ind-1, difflist))
                difflist.append((abs(s1[ind] - s1[ind-1]), ind-1))
                
            k -= 1
            difflist.sort(key=lambda v:v[0])
            difflist.reverse()

        elif diff1 < maxdiff and diff2 > maxdiff:
            newdiff = diff1
            s1[ind+1], s2[ind+1] = s2[ind+1], s1[ind+1]
            difflist.append((newdiff, ind))
            if (ind + 1 < n - 1):
                difflist = list(filter(lambda t: t[1] != ind+1, difflist))
                difflist.append((abs(s1[ind+1] - s1[ind+2]), ind+1))
                
            k -= 1
            difflist.sort(key=lambda v:v[0])
            difflist.reverse()
        
    max_diff = max(abs(s1[i] - s1[i+1]) for i in range(n-1))
    print(max_diff)
    print(difflist)


t = int(input())
for _ in range(t):
    testCase()

