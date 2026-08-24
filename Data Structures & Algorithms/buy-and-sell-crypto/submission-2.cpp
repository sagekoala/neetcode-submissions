class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0, profit = 0;
        for (int R = L + 1; R < prices.size(); R++) {
            if (prices[R] < prices[L]) {
                L = R;
                continue;
            }
            profit = max(prices[R] - prices[L], profit);
        }
        return profit;
    }
};
