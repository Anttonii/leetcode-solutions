/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    queue<int> q;
    void handleList(vector<NestedInteger>& l)
    {
        int lsize = l.size();
        if(lsize == 0) return;

        for(int j = 0; j < lsize; j++)
        {
            if(l[j].isInteger())
                q.push(l[j].getInteger());
            else
                handleList(l[j].getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = 0; i < nestedList.size(); i++)
        {
            if(nestedList[i].isInteger())
                q.push(nestedList[i].getInteger());
            else
                handleList(nestedList[i].getList());
        }
    }
    
    int next() {
        int c = q.front();
        q.pop();
        return c;
    }
    
    bool hasNext() {
        return q.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */