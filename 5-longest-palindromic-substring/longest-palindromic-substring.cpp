class Solution {
public:
    bool solve(int i, int j, string &s) {             // recursion palindrome check
        if (i >= j) {
            return true;
        }
        if (s[i] == s[j]) {
            return solve(i+1, j-1, s);  
        } 
        else {
            return false;
        }
    }

    string longestPalindrome(string s) {
        int Maxlen = 0;  
        int sp = 0; // starting ppont


        for (int i = 0; i < s.length(); i++) {

            for (int j = i; j < s.length(); j++) {                  // sare substring dekh lenge

                if (solve(i, j, s) == true) {
                    
                    if (j - i + 1 > Maxlen) {
                        Maxlen = j - i + 1;         // maleng update
                        sp = i;                     // starting point ka ttrack
                    }
                }
            }
        }
        return s.substr(sp, Maxlen);  // starting points leke end tak substring return
    }
};
