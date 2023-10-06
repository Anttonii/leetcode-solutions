class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        
        int occurences = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == val) {
                nums[i] = 101;
                occurences++;
            }
        }
        sort(nums.begin(), nums.end());
        return nums.size() - occurences;
    }
};