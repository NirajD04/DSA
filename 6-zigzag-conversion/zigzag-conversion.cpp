class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        string result;
        int len = s.length();
        int cycleLen = 2 * (numRows - 1);

        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < len; j += cycleLen) {
                result += s[j];
                
                int diag = j + cycleLen - 2 * i;
                if (i > 0 && i < numRows - 1 && diag < len) {
                    result += s[diag];
                }
            }
        }
        return result;
    }
};
