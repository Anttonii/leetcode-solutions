class SeatManager
{
    set<int> s;

public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            s.insert(i);
        }
    }

    int reserve()
    {
        auto it = s.begin();
        int t = *it;
        s.erase(it);
        return t;
    }

    void unreserve(int seatNumber)
    {
        s.insert(seatNumber);
    }
};