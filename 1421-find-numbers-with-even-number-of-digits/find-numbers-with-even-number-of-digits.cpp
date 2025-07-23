class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int count=0;
        while(i<n){
            int digit= nums[i];
            int d=0;
            while(digit>0){
                digit /= 10;
                d++;
                
            }
            if(d%2==0){
                count++;
            }
            i++;
        }
        return count;
    }
};