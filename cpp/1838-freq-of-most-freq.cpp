class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        if(nums.size() <= 1) return nums.size();

        sort(nums.begin(), nums.end());
        long long t = 0;
        int res = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            t += nums[i];
            while(t + k < ((long long) nums[i] * (i - j + 1)))
            {
                t -= nums[j];
                j++;
            }
            res = max(res, i-j+1);
        }

        return res;
    }
};