class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = s.split(" ")
        res = []
        
        for i in range(len(l)):
            res.append(l[i][::-1])
        
        return ' '.join(res)