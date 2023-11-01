class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < 31; i++)
        {
            int bits = 0;
            for(int num : nums)
                if((num & (1 << i)) != 0) bits++;
            int bitsOff = nums.size() - bits;
            total += (bits * bitsOff);
        }
        return total;
    }
};