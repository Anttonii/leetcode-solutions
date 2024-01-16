class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        unordered_map<char, bool> cm;
        int mxf = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (!cm[s[i]])
            {
                for (int j = s.length(); j-- > 0;)
                {
                    if (s[j] == s[i])
                        mxf = max(mxf, j - i - 1);
                }
                cm[s[i]] = true;
            }
        }
        return mxf;
    }
};