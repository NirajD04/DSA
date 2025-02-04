class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a=0;
        for(int num:nums){
            a^=num;
        }
        return a;
    }
};