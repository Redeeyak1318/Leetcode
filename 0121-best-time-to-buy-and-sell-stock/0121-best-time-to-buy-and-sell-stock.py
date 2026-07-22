class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minPrice = prices[0]
        maxprof = 0
        for i in prices:
            minPrice = min(minPrice, i)
            maxprof = max(maxprof, i - minPrice)
        return maxprof