class Solution {
public:
    void manipString(string& s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '#')
            {
                if(i == 0)
                    s.erase(s.begin() + i, s.begin() + i + 1);
                else
                {
                    s.erase(s.begin() + i - 1, s.begin() + i + 1);
                    i--;
                }
                i--;
            }
        }  
    }
    
    bool backspaceCompare(string s, string t) {
        // time complexity o(n) space complexity o(1)
        manipString(s);
        manipString(t);

        return s == t;
    }
};