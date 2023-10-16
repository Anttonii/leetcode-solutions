class Solution {
public:
    // code is fairly self-explainatory
    // time complexity o(n), space complexity o(1)
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int currMax = -1;
        while (i < j)
        {
            currMax = max(currMax, min(height[i], height[j]) * (j-i));
            
            if(height[i] < height[j]) i++;
            else j--;
        }
        return currMax;
    }
};