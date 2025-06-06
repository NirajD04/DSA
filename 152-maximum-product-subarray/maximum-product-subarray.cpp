class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = nums[0];

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            if (prefix == 0) {
                prefix = 1;
            }
            prefix *= nums[i];
            if (prefix > maxProduct) {
                maxProduct = prefix;
            }
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (suffix == 0) {
                suffix = 1;
            }
            suffix *= nums[i];
            if (suffix > maxProduct) {
                maxProduct = suffix;
            }
        }

        return maxProduct;
    }
};
