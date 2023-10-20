class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        set<int> s;
        for(int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }

        int total = 0;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            s.insert(it->second);
            total++;
        }

        return s.size() == m.size();
    }
};