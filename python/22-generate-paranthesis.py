class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # backtracking and recursion
        stack = []
        res = []
        def recursion(s, m, o, res):
            if m == 0 and len(stack) == 2*n: res.append("".join(stack))
            if m > 0:
                s.append('(')
                recursion(s, m - 1, o + 1, res)
                s.pop()
            if o > 0:
                s.append(')')
                recursion(s, m, o-1, res)
                s.pop()
        
        recursion(stack, n, 0, res)
        return res