class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int t = 1;
        s.push(asteroids[0]);

        while(t < asteroids.size())
        {
            if((asteroids[t] < 0 && s.top() < 0) || asteroids[t] > 0) 
            {
                s.push(asteroids[t++]);
                continue;
            }
            
            while(!s.empty() && t < asteroids.size() && asteroids[t] < 0 && s.top() > 0)
            {
                if(-asteroids[t] > s.top())
                    s.pop();
                else if(-asteroids[t] == s.top())
                {
                    s.pop();
                    t++;
                }
                else t++;
            }

            if(s.empty() && t < asteroids.size())
                s.push(asteroids[t++]);
        }

        vector<int> temp;
        while(!s.empty())
        {
            temp.push_back(s.top());
            s.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};