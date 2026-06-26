class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int mini = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            int current_profit = prices[i] - mini;
            max_profit = max(current_profit, max_profit);
            mini = min(mini, prices[i]);
        }
        return max_profit;
    }
};