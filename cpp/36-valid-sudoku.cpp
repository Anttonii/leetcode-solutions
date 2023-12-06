class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool checked[9][9];
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                checked[i][j] = false;

        for (int k = 0; k < 3; k++)
        {
            for (int m = 0; m < 3; m++)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[3 * k + i][3 * m + j] == '.')
                            continue;

                        int n = int(board[3 * k + i][3 * m + j] - '0') - 1;
                        if (checked[3 * k + m][n] == true)
                            return false;
                        else
                            checked[3 * k + m][n] = true;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++)
        {
            bool vvis[9] = {false, false, false, false, false, false, false, false, false};
            bool hvis[9] = {false, false, false, false, false, false, false, false, false};

            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int n = int(board[i][j] - '0') - 1;
                if (vvis[n] == true)
                    return false;
                else
                    vvis[n] = true;
            }

            for (int k = 0; k < 9; k++)
            {
                if (board[k][i] == '.')
                    continue;
                int n = int(board[k][i] - '0') - 1;
                if (hvis[n] == true)
                    return false;
                else
                    hvis[n] = true;
            }
        }

        return true;
    }
};