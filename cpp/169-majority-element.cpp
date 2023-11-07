class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int majority = INT_MAX;
        int occurences = 0;
        for (auto const &x : m)
        {
            if (x.second > occurences)
            {
                majority = x.first;
                occurences = x.second;
            }
        }
        return majority;
    }
};