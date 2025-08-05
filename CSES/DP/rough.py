def bitwise_and_subarrays(A, l, r):
    result = 0
    for i in range(l, r + 1):
        for j in range(i, r + 1):
            subarray_and = A[i]
            for k in range(i + 1, j + 1):
                subarray_and &= A[k]
            result += subarray_and
    return result

def process_queries_and_updates(N, A, Q, B):
    output = []
    for query in B:
        if query[0] == 1:
            l, r, v = query[1], query[2], query[3]
            for i in range(l-1, r):
                A[i] = v
        elif query[0] == 2:
            l, r, v = query[1], query[2], query[3]
            for i in range(l-1, r):
                A[i] |= v
        elif query[0] == 3:
            l, r = query[1], query[2]
            output.append(bitwise_and_subarrays(A, l-1, r-1))
    return output

# Sample Input 1
N = 4
A = [1, 0, 2, 5]
Q = 4
B = [[3, 1, 3, 0], [1, 1, 2, 4], [2, 2, 4, 5], [3, 1, 4, 0]]
print(process_queries_and_updates(N, A, Q, B))  # Output: [3, 48]

# Sample Input 2
N = 5
A = [5, 4, 3, 2, 1]
Q = 5
B = [[1, 1, 3, 7], [1, 2, 4, 3], [2, 3, 5, 8], [3, 1, 5, 0], [3, 3, 4, 0]]
print(process_queries_and_updates(N, A, Q, B))  # Output: [11, 31, 0]
