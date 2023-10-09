class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # simple binary search solution
        # time complexity o(log n) space complexity o(1)
        # you could save time by using an iterative solution instead of recursive one

        ln = len(nums)
        if ln == 0: return [-1,-1]

        def recSearch(lo, hi):
            mid = int(floor((hi + lo) / 2))
            if nums[mid] == target: return mid
            elif mid == hi or mid == lo: return -1
            
            if nums[mid] > target: return recSearch(lo, mid)
            elif nums[mid] < target: return recSearch(mid, hi)
            
        i = -1
        j = -1
        index = recSearch(0, ln)
        if index >= 0:
            i = index
            j = index
            while i - 1 >= 0 and nums[i - 1] == target: i -= 1
            while j + 1 < ln and nums[j + 1] == target: j += 1
        
        return [i, j]