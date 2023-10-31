class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortest = INT_MAX;
        int longest = 0;
        for(int i = 0; i < strs.size(); i++)
            shortest = min(shortest, (int) strs[i].length());

        for(int i = 0; i < shortest; i++)
        {
            bool v = true;
            char f = strs[0][i];
            for(int j = 0; j < strs.size(); j++)
            {
                if(strs[j][i] != f) v = false;
            }
            if(!v) break;
            else longest++;
        }
        return strs[0].substr(0, longest);
    }
};