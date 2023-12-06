class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string res = "";
        int l = -1;
        for (int i = 0; i < num.length() - 2; i++)
        {
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                if (int(num[i] - '0') > l)
                {
                    l = int(num[i] - '0');
                    res = {num[i], num[i], num[i]};
                }
            }
        }
        return res;
    }
};