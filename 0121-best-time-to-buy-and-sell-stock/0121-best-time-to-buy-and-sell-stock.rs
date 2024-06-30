use std::cmp;
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut min_num = prices[0];
        let mut max_profit = 0;
        for price in prices {
            let mut profit = price - min_num;
            max_profit = cmp::max(profit, max_profit);
            min_num = cmp::min(price, min_num);
        }
        max_profit
    }
}