class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int w1len = str1.length();
        int w2len = str2.length();
        stringstream ss;

        int _gcd = gcd(w1len, w2len); // c++17 feature
        for(int i = 0; i < _gcd; i++)
        {
            if(str1[i] != str2[i]) return "";
            ss << str1[i];
        }

        string res(ss.str());
        if(w1len > w2len)
            for(int j = 0; j < w1len; j += res.length())
                for(int k = 0; k < res.length(); k++)
                    if(res[k] != str1[j + k]) return "";
        else
            for(int j = 0; j < w2len; j += res.length())
                for(int k = 0; k < res.length(); k++)
                    if(res[k] != str2[j + k]) return "";

        return res;
    }
};