class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # not very elegant but works
        from collections import deque
        q = deque()
        for c in s:
            if c == '(' or c == '[' or c == '{':
                q.append(c)
            elif c == ')':
                if q and q[-1] == '(':
                    q.pop()
                else:
                    return False
            elif c == ']':
                if q and q[-1] == '[':
                    q.pop()
                else:
                    return False
            elif c == '}':
                if q and q[-1] == '{':
                    q.pop()
                else:
                    return False
            else: return False

        return len(q) == 0
