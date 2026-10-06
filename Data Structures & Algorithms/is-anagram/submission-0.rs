impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut dict = HashMap::new();
        for ch in s.chars() {
            let counter = dict.entry(ch).or_insert(0);
            *counter += 1;
        }

        for ch in t.chars() {
            let counter = dict.entry(ch).or_insert(0);
            *counter -= 1;
        }
        
        for (ch, count) in dict {
            if count != 0 {
                return false;
            }
        }
        return true;
    }
}
