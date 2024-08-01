class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hash_map = {}
        for (index, num) in enumerate(nums):
            if num not in hash_map:
                hash_map[num] = index
            else:
                if abs(hash_map[num] - index) <= k:
                    print(hash_map[num])
                    return True
                else:
                    hash_map[num] = index
        return False