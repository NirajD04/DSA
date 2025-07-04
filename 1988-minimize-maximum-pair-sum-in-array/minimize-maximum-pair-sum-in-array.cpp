class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        priority_queue<int> pq;

        for(int i=0; i< n; i++){
            int sum=nums[i]+ nums[n-1-i];
            pq.push(sum);
        }
        return pq.top();
    }
};