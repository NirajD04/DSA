class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int index=0;
        int l=0;
     
        int r=n-1;

        while(index<= r){
            if(nums[index]==0){
                swap(nums[index], nums[l]);
                l++;
                index++;
            }else if(nums[index]==2){
                swap(nums[index], nums[r]);
                r--;
            }else{
                index++;
            }

        }
        
    }
};