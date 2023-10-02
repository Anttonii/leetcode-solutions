class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        s_sum = 0
        t_sum = 0
        for i in range(len(s)):
            s_sum += ord(s[i])
            t_sum += ord(t[i])
        t_sum += ord(t[len(t)-1])
        return chr(t_sum-s_sum)