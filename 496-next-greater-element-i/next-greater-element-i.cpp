class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;

        vector<int> nextgreater(n, -1);

            for (int i = n - 1; i >= 0; i--) {

            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nextgreater[i] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> result;
        for (int num : nums1) {
            for (int i = 0; i < n; i++) {
                if (nums2[i] == num) {
                    result.push_back(nextgreater[i]);
                    break;
                }
            }
        }
        return result;
    }
};