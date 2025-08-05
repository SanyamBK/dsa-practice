def rebuild_ley_lines(n, edges):
    from collections import defaultdict, deque

    # Graph representation
    graph = defaultdict(list)
    degree = [0] * (n + 1)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
        degree[u] += 1
        degree[v] += 1
    
    # Finding all leaves
    leaves = [i for i in range(1, n + 1) if degree[i] == 1]
    
    # We need to add this many edges to get a complete graph
    t = (n * (n - 1) // 2) - (n - 1)
    
    # Output the number of operations
    result = []
    
    # Use BFS to remove leaves and add new connections
    q = deque(leaves)
    while q and len(result) < t:
        leaf = q.popleft()
        if degree[leaf] == 0:
            continue
        
        # Find a neighbor
        for neighbor in graph[leaf]:
            if degree[neighbor] > 0:
                break
        
        # Sever the edge leaf-neighbor
        graph[leaf].remove(neighbor)
        graph[neighbor].remove(leaf)
        degree[leaf] -= 1
        degree[neighbor] -= 1
        
        # Find two nodes to connect
        u = leaf
        v = None
        for i in range(1, n + 1):
            if degree[i] > 0 and i != u:
                v = i
                break
        
        # Create the new edge u-v
        result.append((leaf, neighbor, u, v))
        
        # Add the new edge in the graph
        graph[u].append(v)
        graph[v].append(u)
        degree[u] += 1
        degree[v] += 1
        
        # If this operation creates a new leaf, add it to the queue
        if degree[neighbor] == 1:
            q.append(neighbor)
        if degree[leaf] == 1:
            q.append(leaf)
    
    # Output the result
    print(len(result))
    for op in result:
        print(*op)

# Example usage:
n = 7
edges = [(1, 2), (2, 3), (3, 1), (4, 5), (5, 6), (6, 7)]
rebuild_ley_lines(n, edges)

n = 2
edges = [(1, 2)]
rebuild_ley_lines(n, edges)
