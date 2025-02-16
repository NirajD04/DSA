class Solution {
public:
    string removeOuterParentheses(string s) {
            stack<char> st;
            string result = "";

            for (int i = 0; i < s.length(); i++) {

                if (s[i] == '(') {
                    if (!st.empty()) {
                        result += s[i];
                    }
                    st.push(s[i]);

                } else if (s[i] == ')') {
                    st.pop();
                    if (!st.empty()) {
                        result += s[i];
                    }

                }
            }
            return result;
        // string ans = "";
        // int depth = 0;

        // for (int i = 0; i < s.length(); i++) {
        //     if (s[i] == '(') {
        //         depth++;
        //         if (depth > 1) {
        //             ans += s[i];
        //         }
                
        //     } else if (s[i] == ')') {

        //         if (depth > 1) {
        //             ans += s[i];
        //         }
        //         depth--;
        //     }
        // }
        // return ans;
    }
};