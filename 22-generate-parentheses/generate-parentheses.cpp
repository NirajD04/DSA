class Solution {
public:
vector<string> ans;
void solve(int left, int right, string curr){
    if(left==0 && right==0){
        ans.push_back(curr);
        return;
    }
    if(left>0){
        solve(left-1, right, curr+"(");
    }
    if(right>left){
        solve(left, right-1, curr+")");
    }
}
    vector<string> generateParenthesis(int n) {
        string temp="";
        solve(n,n,temp);
        return ans;
    }
};