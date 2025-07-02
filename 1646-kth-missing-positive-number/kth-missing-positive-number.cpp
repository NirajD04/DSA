class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int, bool> mp;
        
        // Mark all the elements present in arr
        for(int num : arr) {
            mp[num] = true;
        }

        int count = 0;  // count of missing numbers
        int current = 1; // current number to check

        while(true) {
            if(mp.find(current) == mp.end()) {
                count++;
                if(count == k) {
                    return current;
                }
            }
            current++;
        }

        // This line will never be reached
        return -1;
    }
};
