class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // long long xor_r=0;
        // for (int & num: nums){
        //     xor_r ^= num;
        // }

        // int mask= xor_r & (-xor_r);
        // int groupa=0;
        // int groupb=0;

        // for(int &num:nums){
        //     if(num & mask){
        //         groupa ^= num;
        //     }
        //     else{
        //         groupb ^= num;
        //     }

        // }
        // return {groupa, groupb};

        unordered_map<int, int> mp;
        vector<int> ans;

        for (auto x : nums) {
            mp[x]++;
        }

        for (auto x : mp) {
            if (x.second == 1) {
               ans.push_back(x.first);
            }
        }
        return ans;
    }
};