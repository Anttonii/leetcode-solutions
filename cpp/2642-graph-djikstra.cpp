class Graph
{
    unordered_map<int, vector<pair<int, int>>> nodes;
    int nodesCount = 0;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        nodesCount = n;
        nodes.reserve(n);

        for (int i = 0; i < edges.size(); i++)
            addEdge(edges[i]);
    }

    void addEdge(vector<int> edge)
    {
        nodes[edge[0]].push_back(pair{edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        vector<int> dist(nodesCount, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, node1});
        dist[node1] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (u == node2)
                return dist[u];

            for (auto x : nodes[u])
            {
                int v = x.first;
                int weight = x.second;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};