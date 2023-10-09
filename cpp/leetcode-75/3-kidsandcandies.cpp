class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> hasGreatest;
        hasGreatest.reserve(candies.size());

        int maxCandies = *max_element(candies.begin(), candies.end());
        for(int i = 0; i < candies.size(); i++)
        {
            hasGreatest.push_back(candies[i] + extraCandies >= maxCandies);
        }

        return hasGreatest;
    }
};