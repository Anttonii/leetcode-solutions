class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        res = list(nums1)
        stack = []
        for i in range(len(nums2) - 1, -1, -1):
            while stack and stack[-1] <= nums2[i]:
                stack.pop()

            if len(stack) == 0:
                for j in range(len(nums1)):
                    if nums1[j] == nums2[i]:
                        res[j] = -1
            else:
                for j in range(len(nums1)):
                    if nums1[j] == nums2[i]:
                        res[j] = stack[-1]
            stack.append(nums2[i])
        return res