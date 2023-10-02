class Solution(object):
    def winnerOfGame(self, colors):
        """
        :type colors: str
        :rtype: bool
        """
        # truly a silly problem, what game goes on for approx. 10^5 turns?
        if len(colors) < 3: return False

        alice = 0
        for i in range(1, len(colors) - 1):
            if colors[i-1] == colors[i] == colors[i+1] == 'A':
                alice += 1
            elif colors[i-1] == colors[i] == colors[i+1] == 'B':
                alice -= 1

        return alice > 0