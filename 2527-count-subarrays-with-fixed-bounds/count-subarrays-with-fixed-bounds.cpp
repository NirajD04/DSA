class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long minindex = -1;

        long long maxindex = -1;
        long long culpirateindex = -1;
        
        
        long long ans = 0;

        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int temp = 0;

            if (nums[i] < minK || nums[i] > maxK) {
                culpirateindex = i;
            }
            if (nums[i] == minK) {
                minindex = i;
            }
            if (nums[i] == maxK) {
                maxindex = i;
            }

            int smaller = min(minindex, maxindex);
            temp = smaller - culpirateindex;

            ans += (temp <=0) ? 0 : temp;
        }
        return ans;
    }
};