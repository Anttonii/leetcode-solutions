class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int m = 0;
        if(left.size() != 0)
            m = max(m, *max_element(left.begin(), left.end()));
        if(right.size() != 0)
            m = max(m, n - *min_element(right.begin(), right.end()));

        return min(m,n);
    }
};