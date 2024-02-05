class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int sum = 0;
        int last = 0;
        for (int i = 0; i < bank.size(); i++)
        {
            int count = 0;
            for (auto c : bank[i])
                if (c == '1')
                    count++;
            if (count == 0)
                continue;
            sum += last * count;
            last = count;
        }
        return sum;
    }
};