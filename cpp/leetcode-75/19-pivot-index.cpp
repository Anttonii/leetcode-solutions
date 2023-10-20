class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // time complexity o(3n) space complexity o(2n)
        vector<int> rSums(nums.size() + 1, 0);
        vector<int> lSums(nums.size() + 1, 0);

        lSums[1] = nums[0];
        rSums[nums.size() - 1] = nums[nums.size() - 1];

        for(int i = 0; i < nums.size(); i++)
            lSums[i + 1] = lSums[i] + nums[i];

        for(int i = nums.size() - 1; i-->0;)
            rSums[i] = rSums[i+1] + nums[i];

        for(int i = 0; i < nums.size(); i++)
            if(lSums[i] == rSums[i+1]) return i;

        return -1;
    }
};