impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let n = ratings.len();
        let mut candies = vec![1; n];

        for i in 1..n {
            if ratings[i] > ratings[i - 1] {
                candies[i] = candies[i - 1] + 1;
            } 
        }

        for i in (0..n - 1).rev() {
            if ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1] {
                candies[i] = candies[i + 1] + 1;
            }
        }

        candies.iter().sum()
    }
}