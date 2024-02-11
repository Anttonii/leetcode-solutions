class Solution
{
public:
    int arrangeCoins(int n)
    {
        int c = n;
        int inc = 1;
        while (c - inc > 0)
        {
            c -= inc;
            inc++;
        }
        return inc - 1;
    }
};