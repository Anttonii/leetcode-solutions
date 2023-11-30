class Solution
{
public:
    int mod = 1e9 + 7;
    int numberOfWays(string corridor)
    {
        vector<pair<int, int>> pos;
        int s = -1;
        int sc = 0;
        for (int i = 0; i < corridor.length(); i++)
        {
            if (corridor[i] == 'S')
            {
                sc++;
                if (s == -1)
                    s = i;
                else
                {
                    pos.push_back(pair{s, i});
                    s = -1;
                }
            }
        }

        if (pos.size() <= 1)
            return pos.size();
        if (sc % 2 != 0)
            return 0;

        long long int ans = 1;
        for (int i = 1; i < pos.size(); i++)
        {
            int sse = pos[i - 1].second;
            int sss = pos[i].first;
            int l = sss - sse - 1;
            ans = (ans * (l + 1)) % mod;
        }
        return ans;
    }
};