class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimal = prices[0];
        int n = prices.size();

        int profit = 0;
        for (int i = 1; i < n; i++) {
            int cost = prices[i];

            profit = max(profit, cost - minimal);
            minimal = min(cost, minimal);
        }

        return profit;
    }
};