class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        while (s.length() % k != 0) {
            s += fill;
        }

        int n = s.length();
        for (int i = 0; i < n; i += k) {
            ans.push_back(s.substr(i, k));
        }

        return ans;
    }
};
