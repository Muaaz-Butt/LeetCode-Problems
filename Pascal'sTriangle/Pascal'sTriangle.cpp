#include <iostream>
#include <vector>

//int** generate(int numRows) {
//    int** result = new int* [numRows];
//
//    for (int i = 0; i < numRows; ++i) {
//        result[i] = new int[i + 1]; 
//        result[i][0] = 1; 
//        for (int j = 1; j < i; ++j) {
//            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
//        }
//        result[i][i] = 1; 
//    }
//    return result;
//}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};

