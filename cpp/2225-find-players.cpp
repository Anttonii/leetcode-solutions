class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> res(2, vector<int>{});
        unordered_map<int, pair<int, int>> stats;
        for (int i = 0; i < matches.size(); i++)
        {
            stats[matches[i][0]].first++;
            stats[matches[i][1]].second++;
        }

        for (auto const &p : stats)
        {
            if (p.second.second == 0)
                res[0].push_back(p.first);
            if (p.second.second == 1)
                res[1].push_back(p.first);
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};