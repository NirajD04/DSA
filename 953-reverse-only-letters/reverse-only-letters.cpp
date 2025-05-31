class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0;
        int r = s.length() - 1;
       
        while (l < r) {

            if(!isalpha(s[l])){
                l++;
                continue;
            }
            if(!isalpha(s[r])){
                r--;
                continue;
            }
            else{
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};