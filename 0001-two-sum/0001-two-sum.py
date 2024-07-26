class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}

        for (i, num) in enumerate(nums):
            temp = target - num
            if temp in map:
                return [map[temp], i]
            map[num] = i

        return []