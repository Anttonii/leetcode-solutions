class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int len = rowIndex + 1;
        vector<int> res(len, 1);

        for(int i = 2; i < res.size(); i++)
        {
            for(int j = i; j-- > 1;)
            {
                res[j] = res[j-1] + res[j];
            }
        }

        return res;
    }
};