class Solution {
public:
    string dp(string c, int m, int n)
    {
        if(m == n) return c;
        if(m == 0) return dp(string{"1"}, m+1, n);
        
        stringstream ss;

        int last = int(c[0] - '0');
        int count = 1;
        for(int i = 1; i < c.length(); i++)
        {
            if(int(c[i] - '0') != last)
            {
                ss << count << last;
                last = int(c[i] - '0');
                count = 1;
            }
            else count++;
        }
        ss << count << last;

        return dp(ss.str(), m+1, n);
    }

    string countAndSay(int n) {
        if(n == 1) return string{"1"};
        return dp(string{""}, 0, n);
    }
};