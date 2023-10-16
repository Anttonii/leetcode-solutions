class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // time complexity o(n) space complexity o(1)
        int mx = -1;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) k--;
            while(k < 0)
            {
                if(nums[curr] == 0) k++;
                curr++;
            }
            mx = max(mx, i - curr + 1);
        }
        return mx;
    }
};