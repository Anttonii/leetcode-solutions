class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1;
        string s2;
        for(auto const & x : word1)
            s1 += x;

        for(auto const & x : word2)
            s2 += x;

        if(s1.length() != s2.length()) return false;

        for(int i = 0; i < s1.length(); i++)
            if(s1[i] != s2[i]) return false;
        
        return true;
    }
};