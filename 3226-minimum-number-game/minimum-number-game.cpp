class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();

            pq.pop();
            ;
            ans.push_back(second);
            ans.push_back(first);
        }

        return ans;
    }
};