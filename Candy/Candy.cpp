class Solution {
public:
    int candy(vector<int>& ratings) {
        int noOfCandies = ratings.size();
        int i = 1;
        vector<int> candies(noOfCandies, 1);
        while (i < noOfCandies) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
            i++;
        }
        i = noOfCandies - 2;
        while (i >= 0) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            i--;
        }
        int result = 0;
        for (int j = 0; j < noOfCandies; j++) {
            result += candies[j];
        }
        return result;
    }
};