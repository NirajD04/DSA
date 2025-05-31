class Solution {
public:
    typedef pair<int, char> p;  // frequency first for max-heap
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        priority_queue<p> pq;  // max heap sorted by frequency
        for (auto& [ch, freq] : mp) {
            pq.push({freq, ch});
        }

        string result;
        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();
            result += string(freq, ch);  // append ch freq times
        }

        return result;
    }
};
