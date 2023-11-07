class MyQueue
{
    stack<int> r;
    stack<int> w;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        r.push(x);
    }

    int pop()
    {
        if (w.size() == 0)
        {
            while (r.size() > 0)
            {
                w.push(r.top());
                r.pop();
            }
        }
        int t = w.top();
        w.pop();
        return t;
    }

    int peek()
    {
        if (w.size() == 0)
        {
            while (r.size() > 0)
            {
                w.push(r.top());
                r.pop();
            }
        }
        return w.top();
    }

    bool empty()
    {
        return r.size() + w.size() == 0;
    }
};
