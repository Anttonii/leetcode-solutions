class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        vector<vector<int>> t;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            vector<int> c;
            for (int j = 0; j < matrix.size(); j++)
            {
                c.push_back(matrix[j][i]);
            }
            t.push_back(c);
        }
        return t;
    }
};