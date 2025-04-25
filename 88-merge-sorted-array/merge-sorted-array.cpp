class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int> result(m + n);
        // int i = 0;

        // int j = 0;
        
        // int k = 0;

        // while (i < m && j < n) {

        //     if (nums1[i] <= nums2[j]) {
        //         result[k++] = nums1[i++];
        //     } 
        //     else {
        //         result[k++] = nums2[j++];
        //     }
        // }

        // while (i < m) {
        //     result[k++] = nums1[i++];
        // }
        
        // while (j < n) {
        //     result[k++] = nums2[j++];
        // }

        // for (int l = 0; l < m + n; ++l) {
        //     nums1[l] = result[l];
        // }void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = 0; i < n; ++i)
        nums1[m + i] = nums2[i];
    sort(nums1.begin(), nums1.end());


    }
};