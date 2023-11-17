class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int sum = 0;
        vector<int> mxR(grid.size());
        vector<int> mxC(grid.size());
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                mxC[i] = max(mxC[i], grid[i][j]);
                mxR[i] = max(mxR[i], grid[j][i]);
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int t = grid[i][j];
                grid[i][j] = min(mxC[i], mxR[j]);
                sum += grid[i][j] - t;
            }
        }
        return sum;
    }
};