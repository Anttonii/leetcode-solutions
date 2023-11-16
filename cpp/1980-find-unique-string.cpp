class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> i(nums.size(), -1);
        stringstream ss;
        for(int i = 0; i < nums.size(); i++)
        {
            char determined = nums[i][i] == '0' ? '1' : '0';
            ss << determined;
        }
        return ss.str();
    }
};