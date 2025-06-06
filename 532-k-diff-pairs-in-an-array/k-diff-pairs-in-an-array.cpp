class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (auto x : nums) {
            freq[x]++;
        }

        int count = 0;
        for (auto x : freq) {

            if (k == 0) {
                if (x.second > 1) {
                    count++;
                }
            } else if (freq.find(x.first + k) != freq.end()) {
                count++;
            }
        }
        return count;
    }
};