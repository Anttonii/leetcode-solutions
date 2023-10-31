class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int last = pref[0];
        for(int i = 1; i < pref.size(); i++)
        {
            int c = last ^ pref[i];
            last = pref[i];
            pref[i] = c;
        }
        return pref;
    }
};