class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start <= end) {
            swap(nums[start], nums[end]);

            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
         k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);

        reverse(nums, k, n - 1);
    }
};

//    int n = nums.size();
//     vector<int> ans(n);
//     for (int i = 0; i < n; i++) {
//         int newindex = (i + k) % n;
//         ans[newindex] = nums[i];
//     }
//     nums = ans;