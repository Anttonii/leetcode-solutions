class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // a bit silly one after 16
        // time complexity o(n) space complexity o(1)
        int k = 1;
        int mx = 0;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) k--;
            while(k < 0)
            {
                if(nums[curr] == 0) k++;
                curr++;
            }
            mx = max(mx, i - curr);
        }
        return mx;
    }
};