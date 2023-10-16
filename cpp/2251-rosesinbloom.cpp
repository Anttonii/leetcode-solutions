class Solution {
public:
    int bsearch(vector<int>& b, int val, int s, int e)
    {
        if(s > e) return s-1;

        int mid = (int) floor((s+e)/2);
        if(b[mid] > val) return bsearch(b, val, s, mid-1);
        else if(b[mid] < val) return bsearch(b, val, mid+1, e);
        else 
        {
            // if there is a duplicate case, search for the largest index for which b[i] == val with binary search
            if(mid + 1 < b.size() && b[mid] == b[mid+1]) return bsearch(b, val, mid+1, e);
            else return mid;
        }
    } 

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // uses a modified bsearch to determine the numbers that are in bloom and number that has quit blooming
        // time complexity o(n*logn) I think, certainly less than o(n^2)
        // space complexity o(n), more precisely o(4*n)
        vector<int> bloomingTimes;
        vector<int> bloomingEnds;
        vector<int> res(people.size());
        for(int i = 0; i < flowers.size(); i++)
        {
            bloomingTimes.push_back(flowers[i][0]);
            bloomingEnds.push_back(flowers[i][1]);
        }
        sort(bloomingTimes.begin(), bloomingTimes.end());
        sort(bloomingEnds.begin(), bloomingEnds.end());

        for(int i = 0; i < people.size(); i++)
        {
            int bts = bsearch(bloomingTimes, people[i], 0, bloomingTimes.size() - 1) + 1;
            // take people[i] - 1 since we find to the largest index for which have already quit blooming
            // and the flowers are still blooming on index of people[i]. 
            int bte = bsearch(bloomingEnds, people[i] - 1, 0, bloomingEnds.size() - 1) + 1;
            res[i] = bts - bte;
        }
        return res;
    }
};