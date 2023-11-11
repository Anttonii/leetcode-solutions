class Solution
{
    long long mod = 1000000007;

public:
    int countHomogenous(string s)
    {
        long long res = 0;
        for (int j = 0; j < s.length(); j++)
        {
            long long c = 1;
            long long cc = c;
            while (j + 1 < s.length() && s[j + 1] == s[j])
            {
                c++;
                cc = (cc % mod) + (c % mod);
                j++;
            }
            res = (res % mod) + (cc % mod);
        }
        return (int)res;
    }
};