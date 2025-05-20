class Solution {
public:
    vector<string> ans;

    void solve(int n, string curr) {

        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        solve(n, curr + '1');

    
        if (curr.empty() || curr.back() != '0') {
            solve(n, curr + '0');
        }
    }

    vector<string> validStrings(int n) {
        solve(n, "");
        return ans;
    }
};
