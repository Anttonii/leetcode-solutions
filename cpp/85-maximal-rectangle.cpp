class Solution {
public:
    int determineLargest(vector<int>& h)
    {
        int maxFound = 0;
        stack<int> s;

        for(int i = 0; i < h.size() + 1; i++)
        {
            while(!s.empty() && (i == h.size() || h[s.top()] >= h[i]))
            {
                int height = h[s.top()];
                s.pop();
                int width;
                if(s.empty()) width = i;
                else width = i - s.top() - 1;
                maxFound = max(maxFound, width * height);
            }
            s.push(i);
        }

        return maxFound;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxFound = 0;
        vector<int> h(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                int d = int(matrix[i][j] - '0');
                if(d == 0) h[j] = 0;
                else h[j]++;
            }
            maxFound = max(maxFound, determineLargest(h));
        }
        return maxFound;
    }
};