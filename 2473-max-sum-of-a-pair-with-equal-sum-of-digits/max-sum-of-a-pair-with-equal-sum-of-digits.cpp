class Solution {
public:
    // vector<int> digits;

    // void sumofdigit(vector<int>& nums) {

    //     for (int x : nums) {
    //         int sum = 0;
    //         while (x > 0) {
    //             sum += x % 10;
    //             x /= 10;
    //         }
    //         digits.push_back(sum);
    //     }
    // }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxsum = -1;

        for (int x : nums) {
            int sum = 0;
            int temp = x;
            while (temp > 0) { // digits sum;

                sum = sum + temp % 10;
                temp = temp / 10;
            }

            if (mp.find(sum) != mp.end()) {
                maxsum = max(maxsum, mp[sum] + x);
            }
            mp[sum] = max(mp[sum], x);
        }
        return maxsum;
    }
};
