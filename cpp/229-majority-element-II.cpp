class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // implements moore's voting algorithm
        // time complexity o(n), space complexity o(n/3)
        int n = nums.size();
        if (n < 2) 
        {
            return vector<int>(nums);
        }

        vector<int> res;
        res.reserve(floor(n / 3) + (n % 3));
        
        // start by sorting in ascending order
        sort(nums.begin(), nums.end());
        
        // set candidate out of bounds of constraints to avoid collisions.
        int candidate = -10^9 - 1;
        int votes = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (votes == 0)
            {
                candidate = nums[i];
                votes++;
            }
            else
            {
                if (candidate != nums[i])
                {
                    candidate = nums[i];
                    votes = 0;
                }
                votes++;
            }

            if(votes > floor(n/3)) 
            {
                res.push_back(candidate);
                while(i + 1 < nums.size() && nums[i + 1] == candidate) // iterate over duplicates
                    i++;
                
                candidate = -10^9 - 1;
                votes = 0;
            }
        }

        return res;
    }
};