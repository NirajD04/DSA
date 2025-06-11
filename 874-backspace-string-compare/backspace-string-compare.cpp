class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;

        for (char x : s) {
            if (x == '#') {
                if (!st1.empty()) st1.pop();
            } else {
                st1.push(x);
            }
        }

        for (char x : t) {
            if (x == '#') {
                if (!st2.empty()) st2.pop();
            } else {
                st2.push(x);
            }
        }

        return st1 == st2;
    }
};
