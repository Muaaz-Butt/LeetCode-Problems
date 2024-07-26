class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(1, len(matrix)):
            for j in range(0, i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        j = 0
        k = len(matrix[0]) - 1

        while j < k:
            for i in range(0, len(matrix)):
                matrix[i][j], matrix[i][k] = matrix[i][k], matrix[i][j]
            j += 1
            k -= 1