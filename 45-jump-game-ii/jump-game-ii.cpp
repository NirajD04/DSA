class Solution {
public:
    int jump(vector<int>& nums) {
         int jumps = 0, farthest = 0, current_end = 0;
    
    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        
        if (i == current_end) {  // Must take a jump
            jumps++;
            current_end = farthest;
        }
    }
    
    return jumps;
    }
};