class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1len = word1.length();
        int w2len = word2.length();
        int shortest = min(w1len, w2len);

        stringstream ss;
        for (int i = 0; i < shortest; i++)
        {
            ss << word1[i] << word2[i];
        }

        if(w1len == shortest)
            ss << string(word2.begin() + shortest, word2.end());
        else
            ss << string(word1.begin() + shortest, word1.end());

        return ss.str();
    }
};