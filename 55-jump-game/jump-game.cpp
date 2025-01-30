class Solution {
public:
    bool canJump(vector<int>& nums) {
            int farthest = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > farthest) return false;  // Stuck, can't move forward
        farthest = max(farthest, i + nums[i]);
        if (farthest >= nums.size() - 1) return true;  // Can reach last index
    }
    return true;

    }
};