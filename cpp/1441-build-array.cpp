class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string s[2] = {"Push", "Pop"};
        vector<string> v;
        int k = 1;
        while(true)
        {
            v.push_back(s[0]);
            if(k == target[target.size() - 1]) break;
            // use find here since target has max size of 100
            // for bigger inputs use binary search
            auto r = find(target.begin(), target.end(), k);
            if(r == target.end()) v.push_back(s[1]);
            k++;
        }
        return v;
    }
};