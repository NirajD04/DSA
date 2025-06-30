class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x: nums){
            mp[x]++;
        }

        int result=0;
        for(int num: nums){
            int mini= num;
            int maxi= num+1;

            if(mp.count(maxi)){
                result=max(result, mp[mini]+ mp[maxi] );
            } 

        }
        return result;
    }
};