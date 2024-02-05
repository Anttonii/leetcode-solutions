class Solution
{
public:
    int returnToBoundaryCount(vector<int> &nums)
    {
        int c = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            c += nums[i];
            if (c == 0)
                b++;
        }
        return b;
    }
};