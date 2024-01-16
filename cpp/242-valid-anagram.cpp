class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> l;
        for(int i = 0; i < s.length(); i++)
            l[s[i]]++;
        for(int j = 0; j < t.length(); j++)
        {
            if(l[t[j]] <= 0) return false;
            else l[t[j]]--;
        }
        return true;
    }
};