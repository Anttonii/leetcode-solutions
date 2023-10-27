class Solution {
public:
    int dp_table[101][101];
    int uniquePaths(int m, int n) {
        for(int i = 0; i < m; i++)
            dp_table[i][0] = 1;
        for(int j = 0; j < n; j++)
            dp_table[0][j] = 1;

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-1];
        
        return dp_table[m-1][n-1];
    }
};