class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        for (auto& [ch, count] : freq) {   // agr koye character jada bar hoga to return 
            if (count > (n + 1) / 2)
                return "";
        }

        priority_queue<pair<int, char>> pq;

        for (auto& [ch, f] : freq) {
            pq.push({f, ch}); // freq, character
        }

        string result = "";

        pair<int, char> prev = {0, '#'}; // to keep track

        while (!pq.empty()) {

            auto [f, ch] = pq.top();
            pq.pop();
            result += ch;

            if (prev.first > 0) {
                pq.push(prev); // push back previous char if it still has freq
            }

            prev = {f - 1, ch}; // current char becomes previous
        }

        // check if any two adjacent chars are same
        for (int i = 1; i < result.size(); i++) {

            if (result[i] == result[i - 1]) {
                return "";
            }
        }

        return result;
    }
};