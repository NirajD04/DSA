class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> result(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,candies[i]);
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi){
                result[i]=true;
            }
            else{
                result[i]=false;
            }
        }
        return result;
    }
};