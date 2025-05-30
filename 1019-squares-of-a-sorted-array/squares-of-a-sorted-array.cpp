class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]*nums[i]);
        }

        int i=0;
        while(!pq.empty()){
            nums[i]=pq.top();
            pq.pop();
            i++;
        }
        return nums;
    }
};