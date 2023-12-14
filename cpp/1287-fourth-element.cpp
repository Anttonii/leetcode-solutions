class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> f;
        int mxn = 0;
        int mxc = 0;
        for(int i = 0; i < arr.size(); i++)
            f[arr[i]]++;
        for(const auto& v : f)
        {
            if(mxc < v.second) 
            {
                mxn = v.first;
                mxc = v.second;
            }
        }
        return mxn;
    }
};