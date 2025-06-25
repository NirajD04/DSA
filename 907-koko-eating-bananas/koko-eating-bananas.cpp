class Solution {
public:
    bool caneat(vector<int>& piles, int h, int mid) {
        int actualhours = 0;
        for (int x : piles) {
            actualhours += x / mid;

            if (x % mid != 0) {
                actualhours++;
            }
        }
        return actualhours <= h;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (caneat(piles, h, mid)) {
                r = mid; // shrink kar , mid ke peche ke element check kar;;
            }

            else {
                l = mid + 1;
            }
        }
        return l;
    }
};