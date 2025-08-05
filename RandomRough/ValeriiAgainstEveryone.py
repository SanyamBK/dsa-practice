n = int(input())
lst = list(map(int, input().split()))

lst2 = []
for i in range(n):
    lst[i] = 2**lst[i]
    lst2.append(i)

lst.sort()

while True:
    if sum(lst[l1:r1+1]) == sum(lst[l2:r2]):
        print("YES")
        break
    else:
        if sum(lst[l1:r1+1]) < sum(lst[l2:r2]):
            r2 -= 