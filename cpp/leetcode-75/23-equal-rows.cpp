class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<string> cols;
        vector<string> rows;
        for(int i = 0; i < grid.size(); i++)
        {
            string c = "";
            string r = "";

            for(int j = 0; j < grid[i].size(); j++)
            {
                c += to_string(grid[i][j]) + ":";
                r += to_string(grid[j][i]) + ":";
            }

            cols.push_back(c);
            rows.push_back(r);
        }

        int counter = 0;
        for(int i = 0; i < cols.size(); i++)
            for(int j = 0; j < rows.size(); j++)
                if(cols[i] == rows[j]) counter++;

        return counter;
    }
};