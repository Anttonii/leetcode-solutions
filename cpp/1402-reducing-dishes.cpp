class Solution
{
public:
    int calcSum(vector<int> &v)
    {
        int s = 0;
        for (int i = 0; i < v.size(); i++)
            s += (i + 1) * v[i];
        return s;
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        // time complexity o(nlogn) space complexity o(1)
        sort(satisfaction.begin(), satisfaction.end());

        int partition = 0;
        while (partition < satisfaction.size() && satisfaction[partition] < 0)
            partition++;

        if (partition == 0)
            return calcSum(satisfaction);
        if (partition == satisfaction.size())
            return 0;

        int negatives = accumulate(satisfaction.begin(), satisfaction.begin() + partition, 0);
        int positives = accumulate(satisfaction.begin() + partition, satisfaction.end(), 0);

        int toErase = 0;
        while (-negatives > positives)
            negatives -= satisfaction[toErase++];

        satisfaction.erase(satisfaction.begin(), satisfaction.begin() + toErase);
        return calcSum(satisfaction);
    }
};