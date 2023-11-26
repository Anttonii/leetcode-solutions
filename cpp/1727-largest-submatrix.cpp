class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int ans = 0;
        for (int j = 0; j < matrix[0].size(); j++)
            for (int i = 1; i < matrix.size(); i++)
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];

        for (int i = 0; i < matrix.size(); i++)
        {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for (int j = 0; j < matrix[0].size(); j++)
                ans = max(ans, matrix[i][j] * (j + 1));
        }
        return ans;
    }
};