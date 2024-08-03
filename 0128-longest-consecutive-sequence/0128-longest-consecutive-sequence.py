class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)
        current_streak = 0
        longest_streak = 0
        for num in nums:
            if num - 1 not in nums_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in nums_set:
                    current_streak += 1
                    current_num += 1
                longest_streak = max(longest_streak, current_streak)
        return longest_streak 