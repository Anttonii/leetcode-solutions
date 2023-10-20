class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(char c : s)
        {
            if(c == '*')
            {
                if(st.size() > 0) st.pop();
                continue;
            }
            st.push(c);
        }

        string ret = "";
        while(st.size() > 0)
        {
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};