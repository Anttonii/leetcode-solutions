class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        times = []
        for t in timePoints:
            splitted = t.split(':')
            time = int(splitted[0]) * 60 + int(splitted[1])
            times.append(time)

        res = 2**31 - 1        
        times.sort()
        for i in range(0, len(times) - 1):
            res = min(res, times[i+1] - times[i])

        res = min(res, times[0] + 1440 - times[len(times)-1])

        return res