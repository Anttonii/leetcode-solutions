class Solution {
public:
    string sortVowels(string s) {
        vector<int> is;
        vector<char> cs;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                is.push_back(i);
                cs.push_back(s[i]);
            }
        }

        sort(cs.begin(), cs.end());
        for(int i = 0; i < is.size(); i++)
        {
            s[is[i]] = cs[i];
        }
        return s;
    }
};