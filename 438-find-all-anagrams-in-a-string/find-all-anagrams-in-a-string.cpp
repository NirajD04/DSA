class Solution {
public:
    bool allZero(vector<int>& count) {
        for (int num : count) {

            if (num != 0) {
                return false;
            }
        }
        return true;
    }



    vector<int> findAnagrams(string s, string p) {

        int k = p.length();

        vector<int> count(26, 0);

        for (char ch : p) {
            count[ch - 'a']++;
        }


        int i = 0, j = 0;

        int n = s.length();

        vector<int> result;

        while (j < n) {

            count[s[j] - 'a']--;

            if (j - i + 1 == k) {

                if (allZero(count)) {
                    result.push_back(i);
                }

                count[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }

};