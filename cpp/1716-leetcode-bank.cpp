class Solution
{
public:
    int totalMoney(int n)
    {
        int monday = 0;
        int total = 0;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 7 == 0)
            {
                monday++;
                last = monday;
                total += last;
            }
            else
                total += ++last;
        }
        return total;
    }
};