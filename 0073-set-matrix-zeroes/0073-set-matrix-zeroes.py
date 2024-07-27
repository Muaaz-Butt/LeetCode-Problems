class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        row = len(matrix)
        col = len(matrix[0])
        first_row_zero = False
        first_col_zero = False

        for i in range(0, col):
            if matrix[0][i] == 0:
                first_row_zero = True
                break
        
        for i in range(0, row) :
            if matrix[i][0] == 0 :
                first_col_zero = True
                break
        
        for i in range(1, row) :
            for j in range(1, col) :
                if matrix[i][j] == 0 :
                    matrix[0][j] = 0
                    matrix[i][0] = 0
        
        for i in range(1, row) :
            for j in range(1, col) :
                if (matrix[0][j] == 0 or matrix[i][0] == 0) :
                    matrix[i][j] = 0

        if first_row_zero :
            for i in range(0, col) :
                matrix[0][i] = 0
        
        if first_col_zero :
            for i in range(0, row) :
                matrix[i][0] = 0