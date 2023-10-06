class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // djikstras algorithm for lexicographically sorted permutations
        // time complexity ~o(n) space complexity o(1)
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) i--;
        if (i == 0) {
            std::sort(nums.begin(), nums.end());
        }
        else
        {
            int j = nums.size();
            while (j > i && nums[j - 1] <= nums[i - 1]) j--;
            std::swap(nums[j-1], nums[i-1]);
            i++;
            j = nums.size();
            while (i < j) {
                std::swap(nums[i-1], nums[j-1]);
                i++;
                j--;
            }
        }
    }
};