class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        vector<int> r(nums.size());
        vector<int> d{nums[0]};
        for (int i = 1; i < nums.size(); i++)
            d.push_back(d[i - 1] + nums[i]);

        for (int i = 0; i < nums.size(); i++)
        {
            int ls = d[i] - nums[i];
            int rs = d[nums.size() - 1] - d[i];

            int lt = i * nums[i] - ls;
            int rt = rs - (nums.size() - 1 - i) * nums[i];

            r[i] = lt + rt;
        }
        return r;
    }
};