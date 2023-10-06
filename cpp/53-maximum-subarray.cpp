class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // succinct kadane's algorithm
        // time complexity o(n) space complexity o(1)
        int maxSum = -((int) pow(10, 4)) - 1;
        int currSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);

            if(currSum < 0) currSum = 0;
        }

        return maxSum;
    }
};