class Solution(object):
    def checkArithmeticSubarrays(self, nums, l, r):
        """
        :type nums: List[int]
        :type l: List[int]
        :type r: List[int]
        :rtype: List[bool]
        """
        res = []
        for i in range(len(l)):
            k = l[i]
            j = r[i]
            if j - k < 1:
                res.append(False)
                continue

            s = nums[k:j+1]
            s.sort()

            diff = s[1] - s[0]
            failed = False
            for x in range(1, len(s)):
                if s[x] - s[x-1] != diff:
                    res.append(False)
                    failed = True
                    break
            
            if failed is False:
                res.append(True)
        return res