class Solution {
public:
    string reverseWords(string s) {
        vector<string> strings;
        stringstream ss;
        for(int i = 0; i < s.length(); i++)
        {
            while(isspace(s[i])) i++;
            if(i >= s.length()) continue;

            while(isalpha(s[i]) || isdigit(s[i])) 
            {
                ss << s[i];
                i++;
            }
    
            strings.push_back(ss.str());
            ss.str(std::string());
        }

        int words = strings.size() - 1;
        string ret;
        for(int i = 0; i < words + 1; i++)
        {
            ret = ret + strings[words - i];
            if(i != words) ret = ret + " ";
        }

        cout << ret;
        return ret;
    }
};