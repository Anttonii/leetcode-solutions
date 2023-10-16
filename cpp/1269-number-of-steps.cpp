class Solution {
public:
    static const int mod = 1000000007;

    int dpa[501][501];
    int len;

    int dp(int pos, int steps)
    {
        if(pos < 0 || pos >= len) return 0;
        if(steps == 0) return pos == 0;

        if(dpa[pos][steps] != -1) return dpa[pos][steps];

        int curr = dp(pos + 1, steps - 1);
        curr = (curr + dp(pos - 1, steps - 1)) % mod;
        curr = (curr + dp(pos, steps - 1)) % mod;

        return dpa[pos][steps] = curr;
    }

    int numWays(int steps, int arrLen) {
        // recursive dp solution
        // after battling with this for 1 hr i realised that checking against 0
        // on line 13 was a grave mistake.

        // time complexity o(len * states) as len stated below
        // space complexity is o(1) where all memory is allocated before hand
        // not a crazy amount of memory spent
        len = min((int) floor((steps / 2) + 1), arrLen);
        memset(dpa, -1, sizeof(dpa));
        return dp(0, steps);
    }
};