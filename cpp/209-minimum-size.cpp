class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int shortest = INT_MAX;
        int rsum = 0;
        int j = 0;
        int s = 0;
        while(j < nums.size())
        {
            rsum += nums[j];
            j++;
            if(rsum >= target) 
            {
                while(rsum - nums[s] >= target)
                {
                    rsum -= nums[s];
                    s++;
                }
                shortest = min(shortest, j - s);
            }
        }
        return shortest == INT_MAX ? 0 : shortest;
    }
};