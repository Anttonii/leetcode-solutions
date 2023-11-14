class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> v(26, pair {-1, -1});

        for(int i = 0; i < s.length(); i++)
        {
            if(v[s[i] - 'a'].first == -1) v[s[i] - 'a'].first = i;
            else v[s[i] - 'a'].second = i;
        }

        int t = 0;
        for(const auto & cc : v)
        {
            if(cc.second == 0) continue;

            set<char> cs;
            for(int i = cc.first + 1; i < cc.second; i++)
                cs.insert(s[i]);
            t += cs.size();
        }
        return t;
    }
};