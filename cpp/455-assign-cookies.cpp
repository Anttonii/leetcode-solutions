class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int si = 0;
        int gi = 0;
        while (si < s.size() && gi < g.size())
        {
            if (s[si] >= g[gi])
            {
                si++;
                gi++;
            }
            else
                si++;
        }

        return gi;
    }
};