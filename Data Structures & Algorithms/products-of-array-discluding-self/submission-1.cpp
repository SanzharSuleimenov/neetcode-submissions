class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        int product = 1;
        for (int i = size - 1; i >= 0; i--) {
            product *= nums[i];
            result[i] = product;
        }
        product = 1;
        for (int i = 0; i < size - 1; i++) {
            result[i] = product * result[i + 1];
            product *= nums[i];
        }
        result[size - 1] = product;
        
        return result;
    }
};
