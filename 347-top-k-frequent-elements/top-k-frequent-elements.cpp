class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Use min-heap of size k
        // Stores (frequency, element)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto& entry : freq) {
            pq.push({entry.second, entry.first});

            if (pq.size() > k) {
                pq.pop(); // remove least frequent
            }
        }

        // Step 3: Extract elements
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
