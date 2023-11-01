class MinStack {
public:
    int min;
    vector<pair<int, int>> v;
    
    MinStack() {
        min = INT_MAX;
        v.reserve(30000);
    }
    
    void push(int val) {
        v.push_back(pair{val, min});
        if(val < min) min = val;
    }
    
    void pop() {
        if (v.back().first == min) min = v.back().second;
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */ 