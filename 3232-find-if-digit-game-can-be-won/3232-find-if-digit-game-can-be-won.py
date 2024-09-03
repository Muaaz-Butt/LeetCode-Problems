class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        sum_less_than_10 = 0
        sum_greater_than_10 = 0
        for num in nums:
            if num < 10:
                sum_less_than_10 += num
            else:
                sum_greater_than_10 += num
        return sum_less_than_10 != sum_greater_than_10