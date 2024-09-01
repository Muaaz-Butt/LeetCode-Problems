class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != m * n:
            return []

        result = []
        for i in range(m):
            row = original[i * n:(i + 1) * n]
            result.append(row)

        return result