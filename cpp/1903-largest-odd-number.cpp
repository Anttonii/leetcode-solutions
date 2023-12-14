class Solution
{
public:
    string largestOddNumber(string num)
    {
        int index = 0;
        bool found = false;
        for (int i = num.length(); i-- > 0;)
        {
            if (int(num[i] - '0') % 2 != 0)
            {
                found = true;
                index = i;
                break;
            }
        }
        if (!found)
            return "";
        return num.substr(0, index + 1);
    }
};