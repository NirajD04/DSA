class Solution {
public:
    vector<string> ans;
    void solve(int left, int right, string temp) {
        if (left == 0 && right == 0) {  // zero hone pe ans 
            ans.push_back(temp);
            return;
        }

        if (left > 0) {   // left me (  push kiya baki recursion
            solve(left - 1, right, temp + "(");
        }
        if (right > left) {   // same right me
            solve(left, right - 1, temp + ")");
        } 
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(n, n, temp);
        return ans;
    }
};