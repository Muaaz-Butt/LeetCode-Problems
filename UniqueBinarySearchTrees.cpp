class Solution {
public:
    int numTrees(int n) {
        long result = 1;
        for (int i = 0; i < n; i++)
            result *= (4 * i + 2) / (i + 2.);
        return result;
    }
};