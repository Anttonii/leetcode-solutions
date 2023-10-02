class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # standard 3sum implementation
        nums.sort()
        numslen = len(nums)
        resl = list()
        prev = -10**5 - 1

        for x in range(numslen - 2):
            a = nums[x]
            if prev == a: continue
            else: prev = a

            k = x + 1
            l = numslen - 1
            while k < l:
                b = nums[k]
                c = nums[l]
                if a + b + c == 0:
                    resl.append([a, b, c])
                    k = k + 1
                    l = l - 1
                elif a + b + c > 0:
                    l = l - 1
                else: k = k + 1

        return [ele for ind, ele in enumerate(resl) if ele not in resl[:ind]]