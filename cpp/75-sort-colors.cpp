class Solution {
public:
    void swap(vector<int>& n, int x, int x2)
    {
        int t = n[x];
        n[x] = n[x2];
        n[x2] = t;
    }
    
    void sortColors(vector<int>& nums) {
        int i = 0;
        int mid = 0;
        int j = nums.size() - 1;
        while (mid <= j)
        {
            if(nums[mid] == 0) 
            {
                swap(nums, i, mid);
                i++;
                mid++;
            }
            else if(nums[mid] == 1) mid++;
            else if(nums[mid] == 2)
            {
                swap(nums, mid, j);
                j--;
            }
        }
    }
};