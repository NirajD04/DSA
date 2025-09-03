class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();

        string ans = "";
        for (int i = 0; i < n; i++) {

            while (ans.length() > 0 && k > 0 && ans.back() > num[i]) {
                ans.pop_back();
                k--;
            }

            if (ans.length() > 0 || num[i] != '0') {
                ans.push_back(num[i]);
            }
        }
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        return ans.empty() ? "0" : ans;
    }
};