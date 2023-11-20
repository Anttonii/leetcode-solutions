class Solution
{
public:
    vector<string> buildString(vector<vector<bool>> b)
    {
        vector<string> res;
        for (const auto &i : b)
        {
            string s = "";
            for (const auto &j : i)
            {
                char c = j ? 'Q' : '.';
                s += c;
            }
            res.push_back(s);
        }
        return res;
    }

    bool check(vector<vector<bool>> &b, int r, int c, int n)
    {
        for (int i = 0; i < c; i++)
            if (b[r][i])
                return false;

        for (int i = r, j = c; i < n && j >= 0; i++, j--)
            if (b[i][j])
                return false;

        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
            if (b[i][j])
                return false;

        return true;
    }

    void solve(vector<vector<string>> &v, vector<vector<bool>> &b, int n, int c)
    {
        if (c >= n)
            v.push_back(buildString(b));

        for (int i = 0; i < n; i++)
        {
            if (!check(b, i, c, n))
                continue;

            b[i][c] = true;
            solve(v, b, n, c + 1);
            b[i][c] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<bool>> b(n, vector<bool>(n, 0));
        vector<vector<string>> v;
        solve(v, b, n, 0);
        return v;
    }
};