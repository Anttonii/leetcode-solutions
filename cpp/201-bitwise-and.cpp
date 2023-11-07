class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int res = 0;
        for (int i = 31; i-- > 0;)
        {
            int b = (left >> i) & 1;
            if (!((left >> i) ^ (right >> i)) == 1)
                res = (b << i) | res;
        }
        return res;
    }
};