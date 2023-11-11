class Solution
{
    int dpa[10001];
    int len = 0;

public:
    void dp(vector<int> &nums, int p, int j)
    {
        if (p >= len - 1)
        {
            dpa[len - 1] = min(j, dpa[len - 1]);
            return;
        }

        if (dpa[p] <= j)
            return;
        dpa[p] = min(j, dpa[p]);

        for (int i = nums[p] + 1; i-- > 0;)
            dp(nums, p + i, j + 1);
    }

    int jump(vector<int> &nums)
    {
        // solved with dp, greedy would be much faster
        len = nums.size();
        for (int i = 0; i < len; i++)
            dpa[i] = INT_MAX;

        dp(nums, 0, 0);
        return dpa[len - 1];
    }
};