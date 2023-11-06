class Solution
{
public:
    string finalString(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'i')
            {
                s.erase(s.begin() + i);
                reverse(s.begin(), s.begin() + i);
                i--;
            }
        }
        return s;
    }
};