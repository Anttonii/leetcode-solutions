class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curr = accumulate(nums.begin(), nums.begin() + k, 0);
        int mxSum = curr;
        for(int i = 0; i < nums.size() - k; i++)
        {
            curr += nums[i + k] - nums[i];
            mxSum = max(mxSum, curr);
        }
        return (double) mxSum / k;
    }
};