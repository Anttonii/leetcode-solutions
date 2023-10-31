class Solution {
public:
    unordered_map<int, vector<char>> m;
    
    void permutate(vector<string>& v, string d)
    {
        int digit = int(d[0] - '0');
        if(v.size() == 0)
        {
            for(int i = 0; i < m[digit].size(); i++)
                v.push_back(string{ m[digit][i] });

            permutate(v, d.substr(1, d.length() - 1));
            return;
        }
        if(d.length() >= 1)
        {
            int s = v.size();
            for(int i = 0; i < s; i++)
            {
                for(int j = 0; j < m[digit].size(); j++)
                {
                    v.push_back(v[i]+m[digit][j]);
                }
            }
            v.erase(v.begin(), v.begin() + s);
            permutate(v, d.substr(1, d.length() - 1));
        }
    }
    
    vector<string> letterCombinations(string digits) {
        m[2] = vector{'a', 'b', 'c'};
        m[3] = vector{'d', 'e', 'f'};
        m[4] = vector{'g', 'h', 'i'};
        m[5] = vector{'j', 'k', 'l'};
        m[6] = vector{'m', 'n', 'o'};
        m[7] = vector{'p', 'q', 'r', 's'};
        m[8] = vector{'t', 'u', 'v'};
        m[9] = vector{'w', 'x', 'y', 'z'};

        vector<string> v;
        v.reserve((int) pow(4, digits.length()));
        if(digits.length() == 0) return v;

        permutate(v, digits);
        return v;
    }
};