class Solution {
public:
    string longestPalindrome(string s) {
        string ret = s.substr(0,1);
        for(int i = 1; i < s.length(); i++)
        {
            int left = i - 1;
            int right = i + 1;  
            while(left >= 0 && right <= s.length() - 1 && s[left] == s[right]) 
            {
                if(ret.size() < right - left + 1) ret = s.substr(left, right - left + 1);
                left--;
                right++;
            }
        }

        for(int i = 0; i < s.length(); i++)
        {
            int left = i;
            int right = i + 1;  
            while(left >= 0 && right <= s.length() - 1 && s[left] == s[right]) 
            {
                if(ret.size() < right - left + 1) ret = s.substr(left, right - left + 1);
                left--;
                right++;
            }
        }

        return ret;
    }
};