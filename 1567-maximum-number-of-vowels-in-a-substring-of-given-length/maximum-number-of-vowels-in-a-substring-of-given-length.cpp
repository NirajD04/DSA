class Solution {
public:
    bool isvowel(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int maxCount = 0;
        int count = 0;
        int i = 0;
        int j = 0;


        
        while (j < n) {

            if (isvowel(s[j])) {
                count++;
            }

            if (j - i + 1 == k) {
                maxCount = max(count, maxCount);
                if (isvowel(s[i])) {
                    count--;
                }
                i++;
            }
            j++;
        }

        return maxCount;
    }
};