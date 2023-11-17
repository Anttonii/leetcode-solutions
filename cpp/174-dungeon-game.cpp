class Solution
{
    int m, n;
    int dpa[201][201];

public:
    int dp(int cn, int cm, vector<vector<int>> &v)
    {
        if (cn > n || cn < 0 || cm > m || cm < 0)
            return INT_MIN;
        if (dpa[cn][cm] != INT_MIN)
            return dpa[cn][cm];
        if (cn == n && cm == m)
            return dpa[cn][cm] = min(0, v[cn][cm]);

        int right = dp(cn, cm + 1, v);
        int down = dp(cn + 1, cm, v);
        if (right != INT_MIN)
            right = min(0, v[cn][cm] + right);
        if (down != INT_MIN)
            down = min(0, v[cn][cm] + down);
        dpa[cn][cm] = max(right, down);
        return dpa[cn][cm];
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        n = dungeon.size() - 1;
        m = dungeon[0].size() - 1;
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < m + 1; j++)
                dpa[i][j] = INT_MIN;
        return abs(dp(0, 0, dungeon)) + 1;
    }
};