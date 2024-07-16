impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut total_tank = 0;
        let mut current_tank = 0;
        let mut starting_index = 0;

        for i in 0..gas.len() {
            let mut temp = gas[i] - cost[i];
            total_tank += temp;
            current_tank += temp;
            
            if current_tank < 0 {
                current_tank = 0;
                starting_index = i + 1 as usize;
            }
        }
        if total_tank < 0 {
            return -1;
        }
        starting_index as i32
    }
}