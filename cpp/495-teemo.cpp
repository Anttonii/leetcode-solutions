class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int total = 0;
        int last = 0;

        for (int i = 0; i < timeSeries.size(); i++)
        {
            int nl = timeSeries[i] + duration;
            total += min(duration, nl - last);
            last = nl;
        }

        return total;
    }
};