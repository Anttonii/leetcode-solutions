class Solution {
public:
    string frequencySort(string s) {
        stringstream ss;
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;

        vector<pair<int, char>> pairs;
        for(auto const& x : m)
            pairs.push_back(pair{ x.second, x.first });

        sort(pairs.begin(), pairs.end(), greater<pair<int, char>>());
        for(int i = 0; i < pairs.size(); i++)
            for(int j = 0; j < pairs[i].first; j++)
                ss << pairs[i].second;

        return ss.str();
    }
};