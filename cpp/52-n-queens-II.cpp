class Solution
{
public:
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

    void solve(vector<vector<bool>> &b, int n, int c, int *a)
    {
        if (c >= n)
            (*a)++;

        for (int i = 0; i < n; i++)
        {
            if (!check(b, i, c, n))
                continue;

            b[i][c] = true;
            solve(b, n, c + 1, a);
            b[i][c] = false;
        }
    }

    int totalNQueens(int n)
    {
        vector<vector<bool>> b(n, vector<bool>(n, 0));
        int res = 0;
        solve(b, n, 0, &res);
        return res;
    }
};