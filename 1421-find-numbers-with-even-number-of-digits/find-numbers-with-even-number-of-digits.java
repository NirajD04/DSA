class Solution {
    int count(int n){
        int digit=0;
        while(n>0){
          n= n/10;
          digit++;
        }
        return digit;
    }
    public int findNumbers(int[] nums) {
        int n= nums.length;
        int ans=0;
        for(int i=0 ; i< n; i++){
            if(count(nums[i])% 2==0){ ans++;}
        }

        return ans;
    }
}