class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if(arr[0] != 1) arr[0] = 1;
        int mx = 1;

        for(int i = 1; i < arr.size(); i++)
        {
            if(abs(arr[i] - arr[i-1]) > 1) arr[i] = arr[i-1] + 1;
            mx = max(mx, arr[i]);
        }

        return mx;
    }
};