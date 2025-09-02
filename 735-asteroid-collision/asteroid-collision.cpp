class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {

            while (!st.empty() && st.top() > 0 && a < 0) {
                int sum = st.top() + a;
                if (sum > 0) {
                    a = 0;
                }
                if (sum < 0) {
                    st.pop();
                }
                if (sum == 0) {
                    a = 0;
                    st.pop();
                }
            }

            if (a != 0) {
                st.push(a);
            }
        }
        int n = st.size();
        vector<int> ans(n);

        while (n>0) {
            ans[n - 1] = st.top();
            st.pop();
            n--;
        }
        return ans;
    }
};