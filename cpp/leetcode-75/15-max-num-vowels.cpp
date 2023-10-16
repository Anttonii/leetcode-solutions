class Solution {
public:
    int maxVowels(string s, int k) {
        // solved with queues
        // unneccessary but works
        // time complexity o(n) space complexity o(k) n = length of string
        const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
        queue<int> q;
        int mx = 0;
        int curr = 0;
        bool found = false;
        for(int i = 0; i < s.length(); i++)
        {
            if(i > k - 1 && q.size() >= 1)
            {
                curr -= q.front();
                q.pop();
            }

            for (char c : vowels) 
            {
                if(c == s[i])
                {
                    q.push(1);
                    curr++;
                    mx = max(mx, curr);
                    found = true;
                    continue;
                }
            }

            if(!found) q.push(0);
            found = false;
        }
        return mx;
    }
};