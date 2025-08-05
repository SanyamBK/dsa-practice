#include <bits/stdc++.h>
using namespace std;

// fordfulkerson
class Edge
{
public:
    int from, to;
    long long flow, capacity;
    Edge *residual;

    Edge(int from, int to, long long capacity)
    {
        this->from = from;
        this->to = to;
        this->capacity = capacity;
        this->flow = 0;
    }

    bool isResidual()
    {
        return capacity == 0;
    }

    long long remainingCapacity()
    {
        return capacity - flow;
    }

    void augment(long long bottleNeck)
    {
        flow += bottleNeck;
        residual->flow -= bottleNeck;
    }

    string toString(int s, int t)
    {
        string u = (from == s) ? "s" : ((from == t) ? "t" : to_string(from));
        string v = (to == s) ? "s" : ((to == t) ? "t" : to_string(to));
        return "Edge " + u + " -> " + v + " | flow = " + to_string(flow) + " | capacity = " + to_string(capacity) + " | is residual: " + to_string(isResidual());
    }
};

class FordFulkerson
{
public:
    int n, m = 0;
    int s, t;
    long long maxFlow;
    vector<vector<Edge *>> adj;
    vector<bool> visited;

    FordFulkerson(int n, int s, int t)
    {
        this->n = n;
        this->s = s;
        this->t = t;
        this->maxFlow = 0;
        this->adj = vector<vector<Edge *>>(n);
        this->visited = vector<bool>(n);
    }

    void addEdge(int from, int to, long long capacity)
    {
        Edge *e1 = new Edge(from, to, capacity);
        Edge *e2 = new Edge(to, from, 0);
        e1->residual = e2;
        e2->residual = e1;
        adj[from].push_back(e1);
        adj[to].push_back(e2);
        m++;
    }

    void dfs(int i)
    {
        visited[i] = true;
        for (Edge *e : adj[i])
        {
            if (e->remainingCapacity() > 0 && !visited[e->to])
            {
                dfs(e->to);
            }
        }
    }

    long long fordFulkerson()
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        long long f = dfs(s, LLONG_MAX);
        while (f != 0)
        {
            maxFlow += f;
            for (int i = 0; i < n; i++)
            {
                visited[i] = false;
            }
            f = dfs(s, LLONG_MAX);
        }
        return maxFlow;
    }

    long long dfs(int i, long long flow)
    {
        if (i == t)
        {
            return flow;
        }
        visited[i] = true;
        for (Edge *e : adj[i])
        {
            if (!visited[e->to] && e->remainingCapacity() > 0)
            {
                long long bottleNeck = dfs(e->to, min(flow, e->remainingCapacity()));
                if (bottleNeck > 0)
                {
                    e->augment(bottleNeck);
                    return bottleNeck;
                }
            }
        }
        return 0;
    }

    void printEdges()
    {
        for (int i = 0; i < n; i++)
        {
            for (Edge *e : adj[i])
            {
                if (e->isResidual())
                {
                    continue;
                }
                cout << e->toString(s, t) << endl;
            }
        }
    }
};

int main()
{
    FordFulkerson ff = FordFulkerson(6, 0, 5);
    ff.addEdge(0, 1, 10);
    ff.addEdge(0, 2, 10);
    ff.addEdge(1, 2, 2);
    ff.addEdge(1, 3, 4);
    ff.addEdge(1, 4, 8);
    ff.addEdge(2, 4, 9);
    ff.addEdge(4, 3, 6);
    ff.addEdge(3, 5, 10);
    ff.addEdge(4, 5, 10);
    cout << ff.fordFulkerson() << endl;
    ff.printEdges();
    return 0;
}