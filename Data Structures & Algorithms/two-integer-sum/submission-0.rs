impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut numbers = HashMap::new();
        for (i, &num) in nums.iter().enumerate() {
            let pair = target - num;
            if let Some(&pair_index) = numbers.get(&pair) {
                return vec![pair_index as i32, i as i32];
            }
            numbers.insert(num, i);
        }
        return vec![];
    }
}
