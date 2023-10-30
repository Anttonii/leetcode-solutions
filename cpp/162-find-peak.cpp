class Solution {
public:
    int bs(vector<int>& v, int l, int h)
    {
        if(l == h) return l;
        int mid = floor((h + l) / 2);

        if(mid == 0) return v[0] > v[1] ? 0 : 1;
        if(mid == v.size() - 1) return v[v.size() - 1] > v[v.size() - 2] ? v.size() - 1 : v.size() - 2;

        if(v[mid] > v[mid-1] && v[mid] > v[mid+1]) return mid;
        else if(v[mid] > v[mid-1]) return bs(v, mid + 1, h);
        else return bs(v, l, mid - 1);
    }

    int findPeakElement(vector<int>& nums) {
        return bs(nums, 0, nums.size() - 1);
    }
};