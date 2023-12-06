class Solution
{
public:
    string decodeString(string s)
    {
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                int start = i;
                while (isdigit(s[i]))
                    i++;
                int len = stoi(s.substr(start, i - start));
                i++; // skip over [
                int ps = i;
                int c = 1;
                while (i < s.length() && c > 0)
                {
                    if (s[i] == '[')
                        c++;
                    if (s[i] == ']')
                        c--;
                    i++;
                }
                i--;
                for (int j = 0; j < len; j++)
                    res += decodeString(s.substr(ps, i - ps));
            }
            if (i < s.length() && isalpha(s[i]))
                res += s[i];
        }
        return res;
    }
};