class Solution {
public:
    int kthGrammar(int n, int k) {
        // no recursion
        // time complexity o(n), space complexity o(1)
        bool flip = false;
        for(int i = n; i-->0;)
        {
            int remainder = k % 2;
            if(remainder == 0)
            {
                flip = !flip;
                k = k/2;
            }
            else
            {
                k = (k+1)/2;
            }
        }
        return flip;
    }
};