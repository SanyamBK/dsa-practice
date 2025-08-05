# def threePalindromicSubstrings(word):
#     n = len(word)
#     if n < 3:
#         return ["Impossible"]

#     dp = [[False] * n for _ in range(n)]
#     for x in range(n):
#         dp[x][x] = True 

#     for k in range(2, n + 1):
#         for a in range(n - k + 1):
#             b = a + k - 1
#             if word[a] == word[b]:
#                 if k != 2:
#                     dp[a][b] = dp[a + 1][b - 1]
#                 else:
#                     dp[a][b] = True

#     for i in range(1, n - 1):
#         for j in range(i + 1, n):
#             if dp[0][i - 1] and dp[i][j - 1] and dp[j][n - 1]:
#                 return [word[0:i], word[i:j], word[j:]]

#     return ["Impossible"]

# word = input()
# result = threePalindromicSubstrings(word)
# print(*result)

def isPalindrome(x):
    i, j = 0, len(x) - 1
    while i < j:
        if x[i] != x[j]:
            return False
        i += 1
        j -= 1
    return True

def threePalindromicSubstrings(S, n):
    staPal, lasPal = [], []
    start = []

    for i in range(len(S) - 2):
        start.append(S[i])
        if isPalindrome(start):
            staPal.append(i)

    last = []
    for j in range(len(S) - 1, 1, -1):
        last.append(S[j])
        if isPalindrome(last):
            lasPal.append(j)

    lasPal = lasPal[::-1]
    midPal = []

    for i in range(len(staPal)):
        for j in range(len(lasPal)):
            if staPal[i] < lasPal[j]:
                midPal.append([staPal[i], lasPal[j]])

    res1, res2, res3 = "", "", ""
    flag = 0

    for i in range(len(midPal)):
        x = midPal[i][0]
        y = midPal[i][1]
        middle = ""

        for k in range(x + 1, y):
            middle += S[k]

        if isPalindrome(middle):
            flag = 1
            res1 = S[0: x + 1]
            res2 = middle
            res3 = S[y: n]
            break

    if flag == 1:
        return [res1, res2, res3]
    else:
        return ["Impossible"]

word = input()
n = len(word)
ans = threePalindromicSubstrings(word, n)
print(*ans)

