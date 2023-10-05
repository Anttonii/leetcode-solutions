def ncr(n, r):
    import math
    f = math.factorial
    return f(n) // f(r) // f(n-r)

class Solution(object):
    def numIdenticalPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return 0

        n = list([0] * 101)
        for i in range(len(nums)):
            n[nums[i]] += 1
        
        pairs = 0
        for p in n:
            if p > 1:
                pairs += ncr(p, 2)
        
        return pairs