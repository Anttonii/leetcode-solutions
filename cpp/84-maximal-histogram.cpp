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

    int largestRectangleArea(vector<int>& heights) {
        return determineLargest(heights);
    }
};