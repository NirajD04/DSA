class Solution {
public:
    vector<string> ans;

    void backtrack(string& s, int i) {
        // ACCEPT: if we've formed a full solution
        if (i == s.length()) {
            ans.push_back(s);
            return;
        }

        // REJECT: not needed here, since all paths are valid

        // EXPLORE: make choices for current character
        if (isdigit(s[i])) {
            // Only one valid path — digits can't change
            backtrack(s, i + 1);
        } else {
            // Choice 1: lowercase
            s[i] = tolower(s[i]);
            backtrack(s, i + 1);

            // UNDO: backtrack and try uppercase
            s[i] = toupper(s[i]);
            backtrack(s, i + 1);

            // No explicit undo needed because we overwrite `s[i]` each time
        }
    }

    vector<string> letterCasePermutation(string S) {
        ans.clear();
        backtrack(S, 0);
        return ans;
    }
};
