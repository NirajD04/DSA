class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int n = nums.size();

        vector<int> result(n);


        int posIndex = 0, negIndex = 1;

        // Distribute numbers alternately into the result array
        for (int num : nums) {
            if (num > 0) {

                result[posIndex] = num;
                posIndex += 2;
                
            } else {
                result[negIndex] = num;
                negIndex += 2;
            }
        }

        return result;
    }
};