class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int x : nums) {
            if (x <= first) {
                first = x;         // smallest so far
            } else if (x <= second) {
                second = x;        // second smallest
            } else {
                return true;       // found third greater than both
            }
        }
        return false;
    }
};
