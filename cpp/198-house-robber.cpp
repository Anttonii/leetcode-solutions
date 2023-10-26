class Solution {
public:
    int maxes[101];
    int dp(vector<int>& nums, int n)
    {
        if(maxes[n] != -1) return maxes[n];

        maxes[n] = max(dp(nums, n - 1), dp(nums, n - 2) + nums[n]);
        return maxes[n];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        memset(maxes,-1,sizeof(maxes));
        maxes[0] = nums[0];
        maxes[1] = max(nums[0], nums[1]);

        for(int i = 0; i < nums.size(); i++)
        {
            dp(nums, i);
        }
        return maxes[nums.size() - 1];
    }
};