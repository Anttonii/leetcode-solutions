class Solution {
public:
    int integerBreak(int n) {
        // a mathetimatical puzzle
        // simple solution is to think any number n can be breaken down into either
        // n/2 number of 2s or 2*floor(n/2) + 3, note 3 = 2 + 1
        // since 3 > 2 * 1 while 3 = 2 + 1
        // remove all threes first and then multiply by whats left
        //
        // time complexity o(n) space complexity o(1)
        if(n <= 3) return (n-1);
        int res = 1;
        while (n > 4)
        {
            res *= 3;
            n -= 3;
        }
        return n * res;
    }
};