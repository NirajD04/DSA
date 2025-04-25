class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int minimal=p[0];


        int profit=0;
        
        for(int i=0; i< p.size();i++){

            int cost=p[i]-minimal;

            profit=max(profit,cost);

            minimal=min(minimal, p[i]);
        }

        return profit;
    }
};