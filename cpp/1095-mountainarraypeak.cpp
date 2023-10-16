/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    pair<int, int> findPeak(MountainArray& arr, int lo, int hi)
    {
        int mid = (int) floor((lo + hi) / 2);

        int curr = arr.get(mid);
        int next = arr.get(mid+1);

        if(curr > next)
            if(curr > arr.get(mid - 1)) return make_pair(mid, curr);
            else return findPeak(arr, lo, mid-1);
        else return findPeak(arr, mid+1, hi);
    }

    int bsearch_left(MountainArray &arr, int lo, int hi, int target)
    {
        if(lo > hi) return -1;
        int mid = (int) floor((lo + hi) / 2);
        int curr = arr.get(mid);

        if(curr > target) return bsearch_left(arr, 0, mid - 1, target);
        else if(curr < target) return bsearch_left(arr, mid + 1, hi, target);
        else return mid;
    }

    int bsearch_right(MountainArray &arr, int lo, int hi, int target)
    {
        if(lo > hi) return -1;
        int mid = (int) floor((lo + hi) / 2);
        int curr = arr.get(mid);

        if(curr > target) return bsearch_right(arr, mid + 1, hi, target);
        else if(curr < target) return bsearch_right(arr, 0, mid - 1, target);
        else return mid;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        // fairly verbose solution
        // time complexity o(log n) space complexity o(1)
        int len = mountainArr.length();
        
        pair<int, int> peak = findPeak(mountainArr, 0, len - 1);
        int peakIndex = peak.first;
        int peakValue = peak.second;
        if(peakValue == target) return peakIndex;
        
        int hIndex = bsearch_right(mountainArr, peakIndex + 1, len - 1, target);
        int lIndex = bsearch_left(mountainArr, 0, peakIndex - 1, target);

        // if lIndex is -1 return hIndex otherwise lIndex since lIndex is always smaller than hIndex
        return lIndex < 0 ? hIndex : lIndex;
    }
};