class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int j = 1;

        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] != nums[i - 1]){
        //         nums[j] = nums[i];
        //         j++;
        //     }
        // }
        // return j;


        int i=0; int j=1;
        
        while(j< nums.size()){

            if(nums[j]!= nums[i]){

                i++;

                nums[i]=nums[j];
            }

            j++;
        }
        
        return i+1;
    }
};