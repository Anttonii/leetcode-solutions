class Solution
{
public:
    int dp(int n, int c, vector<int> &v)
    {
        if (c == n)
            return 1;
        if (c > n)
            return 0;
        if (v[c] != -1)
            return v[c];
        return v[c] = dp(n, c + 1, v) + dp(n, c + 2, v);
    }
    int climbStairs(int n)
    {
        vector<int> v(n, -1);
        return dp(n, 0, v);
    }
};