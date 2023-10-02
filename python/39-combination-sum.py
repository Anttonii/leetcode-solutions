class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        candidates.sort()

        def rcSum(sum, r, i):
            if sum == 0:
                res.append(list(r))
                return
            
            while i < len(candidates) and sum - candidates[i] >= 0:
                r.append(candidates[i])
                rcSum(sum - candidates[i], r, i)
                i += 1
                r.pop()
        
        rcSum(target, list(), 0)
        return res