use std::collections::HashMap;

struct RandomizedSet {
    val_to_index: HashMap<i32, usize>,
    values: Vec<i32>, 
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {

    fn new() -> Self {
        RandomizedSet {
            val_to_index: HashMap::new(),
            values: Vec::new(),
        }
    }
    
    fn insert(&mut self, val: i32) -> bool {
        if self.val_to_index.contains_key(&val) {
            return false;
        }
        self.values.push(val);
        self.val_to_index.insert(val, self.values.len() - 1);
        true
    }
    
    fn remove(&mut self, val: i32) -> bool {
        if let Some(&index) = self.val_to_index.get(&val) {
            let last_element = *self.values.last().unwrap();
            self.values[index] = last_element;
            self.val_to_index.insert(last_element, index);
            self.values.pop();
            self.val_to_index.remove(&val);
            true
        } else {
            false
        }
    }
    
    fn get_random(&self) -> i32 {
        use rand::Rng;
        let mut rng = rand::thread_rng();
        let random_index = rng.gen_range(0..self.values.len());
        self.values[random_index]
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */