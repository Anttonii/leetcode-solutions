class Solution
{
public:
    int getGarbage(vector<string> &g, int i, int *lm, int *lg, int *lp, int tt)
    {
        int t = 0;
        for (int j = 0; j < g[i].length(); j++)
        {
            if (g[i][j] == 'G')
            {
                t += tt - (*lg);
                (*lg) = tt;
            }
            else if (g[i][j] == 'M')
            {
                t += tt - (*lm);
                (*lm) = tt;
            }
            else
            {
                t += tt - (*lp);
                (*lp) = tt;
            }
            t++;
        }
        return t;
    }

    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int res = 0;
        int lm = 0, lg = 0, lp = 0;
        int tt = 0;

        res += getGarbage(garbage, 0, &lm, &lg, &lp, tt);
        for (int i = 1; i < garbage.size(); i++)
        {
            tt += travel[i - 1];
            res += getGarbage(garbage, i, &lm, &lg, &lp, tt);
        }

        return res;
    }
};