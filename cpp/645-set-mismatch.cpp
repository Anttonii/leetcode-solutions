class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int dup = 0;
        int total = (int)((double)nums.size() * ((1 + nums.size()) / 2.0));
        int sum = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1])
                dup = nums[i];
        return vector<int>{dup, total - sum + dup};
    }
};