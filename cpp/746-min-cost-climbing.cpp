class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // iterative solution
        // time complexity o(n) space complexity o(1)
        int s1 = 0;
        int s2 = 0;
        int s3;

        for(int i = 1; i < cost.size(); i++)
        {
            s3 = min(s1 + cost[i-1], s2 + cost[i]);
            s1 = s2;
            s2 = s3;
        }

        return s3;
    }
};