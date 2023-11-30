class Solution
{
public:
    bool dp(vector<int> &v, vector<bool> &vis, int p, int c)
    {
        if (p < 0 || p >= v.size())
            return false;
        if (v[p] == 0)
            return true;
        if (c > v.size())
            return false;

        if (!vis[p])
        {
            vis[p] = true;
            return dp(v, vis, p + v[p], c++) || dp(v, vis, p - v[p], c++);
        }
        else
            return false;
    }

    bool canReach(vector<int> &arr, int start)
    {
        vector<bool> vis(arr.size(), false);
        return dp(arr, vis, start, 0);
    }
};