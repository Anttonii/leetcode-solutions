class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1) return 1;

        int total = 0;
        int i = 0;
        int j = 0;
        int steps = 0;
        while (i < chars.size())
        {
            char c = chars[i];
            while (i != chars.size() && c == chars[i]) 
            {
                steps++;
                i++;
            }

            chars[j] = c;
            j++;
            if(steps > 1)
            {
                string s = to_string(steps);
                for(int i = 0; i < s.length(); i++)
                {
                    chars[j] = s[i];
                    j++;
                    total++;
                }
            }
            total++;
            steps = 0;
        }
        return total;
    }
};