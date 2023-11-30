class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int k = n - 1;
        for (int i = n - 1; i >= 0; i--)
            if (nums[i] >= k - i)
                k = i;
        return k == 0;
    }
};