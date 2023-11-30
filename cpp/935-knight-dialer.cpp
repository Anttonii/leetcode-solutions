class Solution {
public:
    int mod = (int) 1e9 + 7;
    long long int dpa[10][5001];

    long long int dp(int n, int d)
    {
        if(n == 0) return 1;
        if(n > 0 && d == 5) return 0;
        if(dpa[d][n] != 0) return dpa[d][n];

        if(d == 0) return dpa[d][n] = (dp(n-1, 4) + dp(n-1, 6)) % mod;
        else if(d == 1) return dpa[d][n] = (dp(n-1, 6) + dp(n-1, 8)) % mod;
        else if(d == 2) return dpa[d][n] = (dp(n-1, 7) + dp(n-1, 9)) % mod;
        else if(d == 3) return dpa[d][n] = (dp(n-1, 4) + dp(n-1, 8)) % mod;
        else if(d == 4) return dpa[d][n] = (dp(n-1, 0) + dp(n-1, 3) + dp(n-1, 9)) % mod;
        else if(d == 6) return dpa[d][n] = (dp(n-1, 0) + dp(n-1, 1) + dp(n-1, 7)) % mod;
        else if(d == 7) return dpa[d][n] = (dp(n-1, 2) + dp(n-1, 6)) % mod;
        else if(d == 8) return dpa[d][n] = (dp(n-1, 1) + dp(n-1, 3)) % mod;
        else return dpa[d][n] = (dp(n-1, 2) + dp(n-1, 4)) % mod;
    }

    int knightDialer(int n) {
        long long int tot = 0;

        for(int j = 0; j < 10; j++)
            tot = (tot + dp(n - 1, j)) % mod;
        
        return tot;
    }
};