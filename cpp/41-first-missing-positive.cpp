class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] <= 0 || nums[i] > nums.size())
                nums[i] = n + 1;

        for (int i = 0; i < n; i++)
        {
            int a = abs(nums[i]);
            if (a >= 1 && a <= n)
                nums[a - 1] = -abs(nums[a - 1]);
        }

        int c = 1;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] < 0)
                c++;
            else
                return c;
        }

        return c;
    }
};