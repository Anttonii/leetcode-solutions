class Solution {
    long long mod = 1000000007;
public:
    int reverse(int n)
    {
        int remainder, reverse = 0;
        while (n != 0) {
            remainder = n % 10;
            reverse = reverse * 10 + remainder;
            n /= 10;
        }
        return reverse;
    }

    int countNicePairs(vector<int>& nums) {
        long long res = 0;
        unordered_map<int, long long int> freq;
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] - reverse(nums[i]);
            freq[nums[i]]++;
        }

        for(auto const & v : freq)
            res = (res + (v.second*(v.second-1) / 2)) % mod;

        return (int) (res % mod);
    }
};