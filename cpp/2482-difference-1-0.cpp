class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> rv(grid.size(), 0);
        vector<int> cv(grid[0].size(), 0);
        vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    rv[i]++;
                    cv[j]++;
                }
                else
                {
                    rv[i]--;
                    cv[j]--;
                }
            }
        }

        for(int i = 0; i < diff.size(); i++)
        {
            for(int j = 0; j < diff[0].size(); j++)
            {
                diff[i][j] = rv[i] + cv[j];
            }
        }

        return diff;
    }
};