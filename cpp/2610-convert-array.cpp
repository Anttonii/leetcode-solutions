class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> res;
        unordered_map<int, int> occurence;

        for (int i = 0; i < nums.size(); i++)
            occurence[nums[i]]++;

        while (true)
        {
            vector<int> inter;
            for (auto &p : occurence)
            {
                if (p.second > 0)
                {
                    inter.push_back(p.first);
                    p.second--;
                }
            }
            if (inter.size() == 0)
                return res;
            else
                res.push_back(inter);
        }
        return res;
    }
};