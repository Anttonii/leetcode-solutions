class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<int> res;
        res.reserve(arr.size());

        vector<vector<int>> bits(14);
        for(int i = 0; i < arr.size(); i++)
        {
            int c = 0;
            for(int j = 0; j < 14; j++)
            {
                if(arr[i] & (1 << j)) c++;
            }
            bits[c].push_back(arr[i]);
        }

        for(int i = 0; i < bits.size(); i++)
        {
            sort(bits[i].begin(), bits[i].end());
            for(int j = 0; j < bits[i].size(); j++)
            {
                res.push_back(bits[i][j]);
            }
        }

        return res;
    }
};