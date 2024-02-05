class Solution
{
public:
    bool bsearch(int s, long long l, long long h)
    {
        if (l > h)
            return false;
        long long mid = l + (h - l) / 2;
        long long res = mid * mid;
        if (res == s)
            return true;
        else if (res > s)
            return bsearch(s, l, mid - 1);
        else
            return bsearch(s, mid + 1, h);
    }

    bool isPerfectSquare(int num)
    {
        return bsearch(num, 1, num);
    }
};