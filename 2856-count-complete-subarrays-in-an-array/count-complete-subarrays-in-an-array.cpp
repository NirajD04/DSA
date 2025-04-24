class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        int c = st.size();
        int i = 0;
        int j = 0;
        int result = 0;
        unordered_map<int, int> mp;

        while (j < n) {

            mp[nums[j]]++;

            while (mp.size() == c) {
                result += n - j;
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};