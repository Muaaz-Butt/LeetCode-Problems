class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix[0].size(); i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int j = 0, k = matrix[0].size() - 1;

        while (j < k) {
            for (int i = 0; i < matrix.size(); i++) {
                swap(matrix[i][j], matrix[i][k]);
            }
            j++;
            k--;
        }
    }
};