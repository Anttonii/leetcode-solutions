class Solution {
public:
    void swap(vector<vector<int>>& m, int x1, int y1, int x2, int y2)
    {
        int tmp = m[x1][y1];
        m[x1][y1] = m[x2][y2];
        m[x2][y2] = tmp;
    }

    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix[0].size() - 1; i++)
        {
            for(int j = i + 1; j < matrix[0].size(); j++)
            {
                swap(matrix, i, j, j, i);
            }
        }

        for(int i = 0; i < matrix[0].size(); i++)
        {
            int j = 0;
            int k = matrix[0].size() - 1;
            while(j < k)
            {
                swap(matrix, i, j, i, k);
                j++;
                k--;
            }
        }
    }
};