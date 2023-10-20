class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;

        map<char, int> cw1;
        map<char, int> cw2;

        for(int i = 0; i < word1.length(); i++)
        {
            cw1[word1[i]]++;
            cw2[word2[i]]++;
        }

        // make sure both words have all same letters
        for(auto ww1 : cw1)
        {
            auto it = cw2.find(ww1.first);
            if(it == cw2.end()) return false;
        }

        // make sure occurences match regardless of letters
        vector<int> ow1;
        vector<int> ow2;

        for(auto ofw1 : cw1)
            ow1.push_back(ofw1.second);
        for(auto ofw2 : cw2)
            ow2.push_back(ofw2.second);

        sort(ow1.begin(), ow1.end());
        sort(ow2.begin(), ow2.end());

        for(int i = 0; i < ow1.size(); i++)
        {
            if(ow1[i] != ow2[i]) return false;
        }

        return true;
    }
};