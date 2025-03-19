class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{') {
                st.push(c);

            } 

            
            else {
                if (!st.empty()) {
                    if (c == ')' && st.top()== '(') {
                        st.pop();
                    } else if (c == ']' && st.top()== '[') {
                        st.pop();
                    } else if (c == '}' && st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

            if (st.size()==0) {
                return true;
            } else
                return false;
        }
    };