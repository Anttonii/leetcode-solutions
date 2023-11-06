class Solution
{
    int n, m = 0;
    int dpa[201][201];

public:
    int dp(vector<vector<int>> &grid, int i, int j)
    {
        if (i == n && j == m)
            return grid[i][j];
        if (dpa[i][j] != 0)
            return dpa[i][j];

        if (i == n)
            return dpa[i][j] = grid[i][j] + dp(grid, i, j + 1);
        else if (j == m)
            return dpa[i][j] = grid[i][j] + dp(grid, i + 1, j);
        else
            return dpa[i][j] = grid[i][j] + min(dp(grid, i + 1, j), dp(grid, i, j + 1));
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        n = grid.size() - 1;
        m = grid[0].size() - 1;
        return dp(grid, 0, 0);
    }
};