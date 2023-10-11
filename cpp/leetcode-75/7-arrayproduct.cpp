class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> res(nums.size(), 1);
        
        int prod = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            prod *= nums[i - 1];
            res[i] = prod;
        }

        prod = 1;
        for (int i = nums.size(); i-- > 0;)
        {
            res[i] *= prod;
            prod *= nums[i];
        }

        return res;
    }
};