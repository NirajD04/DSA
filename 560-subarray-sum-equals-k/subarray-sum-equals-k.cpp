// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int l=0, r=0;
//         int count=0, sum=0;

//         while(r< nums.size()){
            
//             sum=sum+nums[r];
            
//             if(sum==k){
//                 count++;
//             }
            
//             while(sum>=k){
//                 sum=sum-nums[l];
//                 l++;
//             }
//             r++;
//         }
//       return count;
//     }
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};


