class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        int i = 1, j = n - 1;
      
        while (i < n) {
            nums[i] = arr[j];
            i += 2;
            j--;
        }

        i = 0;
        
        while (i < n) {
            nums[i] = arr[j];
            i += 2;
            j--;
        }
    }
};
