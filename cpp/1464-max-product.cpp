class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = 0;
        int smx = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(smx < nums[i])
            {
                smx = nums[i];
            }
            if(mx < nums[i]) 
            {
                smx = mx;
                mx = nums[i];
            }
        }
        return (mx-1)*(smx-1);
    }
};