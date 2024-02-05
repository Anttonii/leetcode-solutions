class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> freq;
        vector<int> firstOcc(27, -1);
        int fmin = INT_MAX;

        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
            if (firstOcc[s[i] - 'a'] == -1)
                firstOcc[s[i] - 'a'] = i;
        }

        for (auto const &p : freq)
        {
            if (p.second == 1)
                fmin = min(fmin, firstOcc[p.first - 'a']);
        }

        return fmin == INT_MAX ? -1 : fmin;
    }
};