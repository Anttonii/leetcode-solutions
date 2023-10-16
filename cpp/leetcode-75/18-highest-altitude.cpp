class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int s = 0;
        int mx = -2147483646;
        for(int i = 0; i < gain.size(); i++)
        {
            mx = max(mx, s);
            s += gain[i];
        }
        return mx = max(mx, s);
    }
};