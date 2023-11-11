class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < adjacentPairs.size(); i++)
        {
            m[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        int next = -1000001;
        for (auto const &p : m)
        {
            if (p.second.size() == 1)
            {
                next = p.first;
                break;
            }
        }

        vector<int> res;
        res.reserve(adjacentPairs.size() + 1);
        res.push_back(next);
        int prev = next;
        while (res.size() != adjacentPairs.size() + 1)
        {
            int index = m[next][0] == prev ? 1 : 0;
            res.push_back(m[next][index]);
            prev = next;
            next = m[next][index];
        }

        return res;
    }
};