class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        maxprof = 0
        for i in prices:
            minPrice = min(minPrice, i)
            maxprof = max(maxprof, i - minPrice)
        return maxprof