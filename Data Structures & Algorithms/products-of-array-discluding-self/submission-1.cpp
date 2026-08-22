class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> output(n, 1);

        // 1. Compute prefix products: output[i] contains product of all elements to the left of i
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            output[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // 2. Compute suffix products on the fly and multiply into output[i]
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            output[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return output;
    }
};