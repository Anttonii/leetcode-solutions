class Solution
{
    unordered_map<int, vector<int>> m;

public:
    void formGraph(vector<vector<int>> &routes, vector<unordered_set<int>> &nodes)
    {
        for (int i = 0; i < routes.size(); i++)
        {
            for (int j = 0; j < routes[i].size(); j++)
                m[routes[i][j]].push_back(i);
        }

        for (auto const &n : m)
        {
            for (int i = 0; i < n.second.size(); i++)
            {
                for (int j = i + 1; j < n.second.size(); j++)
                {
                    nodes[n.second[i]].insert(n.second[j]);
                    nodes[n.second[j]].insert(n.second[i]);
                }
            }
        }
    }

    int findPath(vector<unordered_set<int>> &nodes, int source, int target, int size)
    {
        bool visited[size];
        memset(visited, 0, sizeof(visited));
        vector<int> sn = m[source];
        vector<int> tn = m[target];
        queue<pair<int, int>> pn;

        for (int i = 0; i < sn.size(); i++)
            for (int j = 0; j < tn.size(); j++)
                if (sn[i] == tn[j])
                    return 1;

        for (int i = 0; i < sn.size(); i++)
            pn.push(pair{sn[i], 1});

        while (!pn.empty())
        {
            pair<int, int> cp = pn.front();
            int curr = cp.first;
            pn.pop();

            if (visited[curr])
                continue;
            visited[curr] = true;

            for (auto it = nodes[curr].begin(); it != nodes[curr].end(); ++it)
            {
                if (*it != curr)
                    pn.push({*it, cp.second + 1});
                for (int i = 0; i < tn.size(); i++)
                    if (tn[i] == *it)
                        return cp.second + 1;
            }
        }
        return -1;
    }

    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        int len = routes.size();
        vector<unordered_set<int>> nodes(len);
        formGraph(routes, nodes);
        return findPath(nodes, source, target, len);
    }
};