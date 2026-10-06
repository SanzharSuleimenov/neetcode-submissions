impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let mut numbers = HashMap::new();

        for num in &nums {
            let counter = numbers.entry(num).or_insert(0);
            *counter += 1;

            if *counter > 1 {
                return true;
            }
        }
        return false;
    }
}
