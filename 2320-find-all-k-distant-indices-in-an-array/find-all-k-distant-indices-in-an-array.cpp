class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> stt;

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) { // j th index hogaya
                for (int j = max(0, i - k);
                     j <= min((int)nums.size() - 1, i + k); ++j) // j ke range
                                                                 // i-k , i+k;
                    stt.insert(j);
            }
        }
        vector<int> ans(stt.begin(), stt.end());
        return ans;
    }
};