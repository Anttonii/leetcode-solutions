class Solution
{
public:
    // pops and pushes from one queue to another
    void pap(queue<int> &q, queue<int> &q2)
    {
        while (!q.empty())
        {
            q2.push(q.front());
            q.pop();
        }
    }

    string predictPartyVictory(string senate)
    {
        string res = "";

        queue<int> rd;
        queue<int> di;

        queue<int> nrd;
        queue<int> ndi;

        for (int i = 0; i < senate.length(); i++)
            senate[i] == 'R' ? rd.push(i) : di.push(i);

        while (res.empty())
        {
            while (!rd.empty() || !di.empty())
            {
                if (di.empty() && !rd.empty())
                {
                    if (!ndi.empty())
                        ndi.pop();
                    nrd.push(rd.front());
                    rd.pop();
                }
                else if (rd.empty() && !di.empty())
                {
                    if (!nrd.empty())
                        nrd.pop();
                    ndi.push(di.front());
                    di.pop();
                }
                else
                {
                    if (rd.front() < di.front())
                        nrd.push(rd.front());
                    else
                        ndi.push(di.front());
                    rd.pop();
                    di.pop();
                }
            }

            if (nrd.empty())
                res = "Dire";
            else if (ndi.empty())
                res = "Radiant";

            pap(nrd, rd);
            pap(ndi, di);
        }

        return res;
    }
};