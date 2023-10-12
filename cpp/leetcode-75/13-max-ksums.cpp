class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // two pointer solution
        // time complexity depends on sorting algo, rest is o(n), space complexity o(1)
        if(nums.size() <= 1) return 0;
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        int operations = 0;
        while(i < j)
        {
            if(nums[i] + nums[j] == k) 
            {
                operations++;
                i++;
                j--;
            }
            else if(nums[i] + nums[j] > k) j--;
            else i++;
        }
        return operations;
    }
};