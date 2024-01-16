class Solution
{
public:
    int dpa[101];
    int dp(string &s, int index)
    {
        if (index == s.length())
            return 1;
        if (s[index] == '0')
            return 0;
        if (dpa[index] != -1)
            return dpa[index];

        int ways = dp(s, index + 1);
        if (index < s.length() - 1 && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')))
            ways += dp(s, index + 2);

        dpa[index] = ways;
        return ways;
    }
    int numDecodings(string s)
    {
        for (int i = 0; i < 101; i++)
            dpa[i] = -1;
        return dp(s, 0);
    }
};