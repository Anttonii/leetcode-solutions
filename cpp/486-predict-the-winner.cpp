class Solution
{
public:
    bool dp(vector<int> &v, int s, int s2, int i, int j, bool t)
    {
        if (j == i)
            return t ? s + v[i] >= s2 : s >= s2 + v[i];

        if (t)
            return dp(v, s + v[i], s2, i + 1, j, false) || dp(v, s + v[j], s2, i, j - 1, false);
        else
            return dp(v, s, s2 + v[i], i + 1, j, true) && dp(v, s, s2 + v[j], i, j - 1, true);
    }

    bool predictTheWinner(vector<int> &nums)
    {
        return dp(nums, 0, 0, 0, nums.size() - 1, true);
    }
};