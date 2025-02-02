class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int> st;

        vector<int> nextGreater(n, -1);

        // Traverse nums2 from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Maintain the stack to keep only potential "next greater" elements
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack is not empty, top of the stack is the next greater element
            if (!st.empty()) {
                nextGreater[i] = st.top();
            }

            // Push the current number onto the stack
            st.push(nums2[i]);
        }
        

        // Build the result array for nums1
        vector<int> result;
        for (int num : nums1) {
            for (int i = 0; i < n; i++) {
                if (nums2[i] == num) {
                    result.push_back(nextGreater[i]);
                    break;
                }
            }
        }
        return result;
    }
};
