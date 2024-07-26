class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_num = prices[0]
        max_profit = 0

        for price in prices:
            profit = price - min_num
            max_profit = max(profit, max_profit)
            min_num = min(price, min_num)
        return max_profit