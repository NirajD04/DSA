class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        int index=0;
        
        vector<int> ans(n);

        for(index=0; index<n; index++){

        int newindex=(index+k)% n;
        
        ans[newindex]=nums[index];
        }
        
        nums=ans;
    }
};

 