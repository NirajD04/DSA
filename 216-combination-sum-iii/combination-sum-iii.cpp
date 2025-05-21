class Solution {
public:
    vector<vector<int>> result;

    void solve(int k, int n, int start, vector<int>& temp) {
        // base case: if k numbers lere

        if (k == 0) {
            if (n == 0) {
                result.push_back(temp); // only if sum matches
            }
            return;
        }

        // 1 se 9 tak
        
        for (int i = start; i <= 9; i++) {
            if (i > n)
                break;

            temp.push_back(i);
            solve(k - 1, n - i, i + 1, temp);
            temp.pop_back();
            // solve(k - 1, n - i, i + 1, temp);
        }

        // if (i > 9 || k < 0 || n < 0)
        //     return;

        // // Take the current number i
        // temp.push_back(i);
        // solve(k - 1, n - i, i + 1, temp);
        // temp.pop_back(); // Backtrack

        // // Do NOT take the current number i    //without loop this is also possible
        // solve(k, n, i + 1, temp);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(k, n, 1, temp);
        return result;
    }
};
