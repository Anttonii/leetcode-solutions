class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;

        int p = (int) pow(2, nums.size());
        for(int i = 0; i < p; i++)
        {
            vector<int> subset;
            for(int j = 0; j < nums.size(); j++)
            {
                if((i & (1 << j)) > 0) subset.push_back(nums[j]);
            }
            subsets.push_back(subset);
        }

        return subsets;
    }
};