class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int se = 2147483647;  // smallest element
        int sse = 2147483647; // second smallest element
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= se) se = nums[i];
            else if(nums[i] <= sse) sse = nums[i];
            else return true;
        }
        return false;
    }
};