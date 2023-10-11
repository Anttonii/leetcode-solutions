class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                int j = i;
                while(j < nums.size() - 1 && nums[j] == 0) j++;
                swap(nums[i], nums[j]);
            }

        }
    }
};