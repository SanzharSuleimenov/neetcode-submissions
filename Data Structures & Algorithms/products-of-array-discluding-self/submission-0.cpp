class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> suffix(size);
        int product = 1;
        for (int i = size - 1; i >= 0; i--) {
            suffix[i] = product;
            product *= nums[i];
        }
        vector<int> result(size);
        product = 1;
        for (int i = 0; i < size; i++) {
            result[i] = product * suffix[i];
            product *= nums[i];
        }
        return result;
    }
};
