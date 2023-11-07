class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        vector<int> t;
        for (int i = 0; i < dist.size(); i++)
            t.push_back((int)ceil((double)dist[i] / (double)speed[i]));
        sort(t.begin(), t.end());
        for (int j = 0; j < t.size(); j++)
            if (t[j] - j <= 0)
                return j;
        return dist.size();
    }
};