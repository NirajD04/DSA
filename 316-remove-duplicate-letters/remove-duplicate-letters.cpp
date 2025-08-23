class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;   // count frequency of each char

        string ans = "";

        for (char ch : s) {
            freq[ch]--; // this occurrence used

            // if already in answer, skip
            if (ans.find(ch) != string::npos) continue;

            // maintain lexicographic order
            while (!ans.empty() && ans.back() > ch && freq[ans.back()] > 0) {
                ans.pop_back();
            }

            ans.push_back(ch);
        }

        return ans;
    }
};
