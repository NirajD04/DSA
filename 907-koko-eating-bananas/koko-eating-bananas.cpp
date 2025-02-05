class Solution {
public:
    bool caneatall(vector<int>& piles, int mid, int h) {
        long long int actualhours = 0;
        for (int x : piles) {
            actualhours += x  / mid;
            if(x%mid!=0){
                actualhours++;
            }  // Efficient ceil(x / mid)
        }
        return actualhours <= h;
    }
   
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 ;
        int r = *max_element(piles.begin(), piles.end());

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (caneatall(piles, mid, h)) {
                r = mid-1 ;  // Fix: Reduce search space correctly
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
