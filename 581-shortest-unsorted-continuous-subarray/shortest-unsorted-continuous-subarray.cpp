class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int s = 0, e = nums.size() - 1, i, mx = INT_MIN, mn = INT_MAX;

        while (s < nums.size() - 1 && nums[s] <= nums[s + 1])
            s++;
            
        if (s == nums.size() - 1)
            return 0;

        while (e > 0 && nums[e] >= nums[e - 1])
            e--;


        i = s;

        while (i <= e)
            mn = min(mn, nums[i]), mx = max(mx, nums[i]), i++;

        while (s > 0 && nums[s - 1] > mn)
            s--;

        while (e < nums.size() - 1 && nums[e + 1] < mx)
            e++;

        return e - s + 1;
    }
};