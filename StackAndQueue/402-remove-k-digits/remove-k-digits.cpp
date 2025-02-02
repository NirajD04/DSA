class Solution {
public:
    string removeKdigits(string num, int k) {
        // stack<int> st;
        // int n = num.size();

        // for (int i = 0; i < n; i++) {

        //     while (!st.empty() && st.top() > num[i] && k > 0) {
        //         st.pop();
        //         k--;
        //     }

        //     if (st.size() > 0 || num[i] != '0')
        //         st.push(num[i]);
        // }

        // while (k > 0 && !st.empty()) {
        //     st.pop();     // pura stack increasing me hai
        //     k--;
        // }

        // string result = "";
        // while (!st.empty()) {
        //     result += st.top();
        //     st.pop();
        // }
        // reverse(result.begin(), result.end());
        // return result.empty() ? "0" : result;

        string result = "";
        int n = num.size();

        for (int i = 0; i < n; i++) {
            while (result.length() > 0 && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }

            if (result.length() > 0 || num[i] != '0') {
                result.push_back(num[i]);
            }
        }

      while(result.length() > 0 && k > 0) {
            result.pop_back();
            k--;
        }


        return result.length() == 0 ? "0" : result;
    }
};