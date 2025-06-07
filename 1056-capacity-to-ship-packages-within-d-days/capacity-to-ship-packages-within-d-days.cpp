class Solution {
public:
    bool canship(vector<int>& weights, int days, int capacity) {

        int currentload = 0;
        int required_days = 1;

        for (int x : weights) {
            if (currentload + x > capacity) {
                required_days++;
                currentload = 0;
            }
            currentload += x;
        }
        return required_days <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
         int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canship(weights, days, mid)) {
                ans = mid;
                high=mid-1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};