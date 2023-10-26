class Solution {
    int mod = 1000000007;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> s(arr.begin(), arr.end());
        unordered_map<int,int> dp;
        for(int x : arr) dp[x] = 1;
        for(int i : arr)
        {
            for(int j : arr)
            {
                if(j > sqrt(i)) break;
                if(i%j == 0  && s.find(i/j) != s.end())
                {
                    long long t = (long long) dp[j] * dp[i/j];
                    if(i/j==j)
                    {
                        dp[i] = (dp[i] + t) % mod;
                    }
                    else
                    {
                        dp[i] = (dp[i] + t * 2) % mod;
                    }
                }
            }
        }

        int total = 0;
        for(auto& [_, v] : dp)
        {
            total = (total + v) % mod;
        }
        return total;
    }
};