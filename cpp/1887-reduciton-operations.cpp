class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int ops = 0;
        int smallest = INT_MIN;
        int inc = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (smallest < nums[i])
            {
                smallest = nums[i];
                inc++;
            }
            ops += inc;
        }

        return ops;
    }
};