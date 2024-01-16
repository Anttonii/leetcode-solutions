class Solution
{
public:
    long long int power(long long x, unsigned int y, int p)
    {
        long long int res = 1;

        x = x % p;
        if (x == 0)
            return 0;

        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % p;

            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
    {
        vector<int> res;
        for (int i = 0; i < variables.size(); i++)
        {
            long long int inter = power(variables[i][0], variables[i][1], 10);
            long long int result = power(inter, variables[i][2], variables[i][3]);

            if (result == target)
                res.push_back(i);
        }
        return res;
    }
};