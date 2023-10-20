class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;
        
        int k = n;
        int nums[3] = {2,3,5};
        for(int i = 0; i < 3; i++)
        {
            while(k % nums[i] == 0) k /= nums[i];
        }
        return k == 1;
    }
};