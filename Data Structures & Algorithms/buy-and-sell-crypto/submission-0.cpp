class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = prices[0];

        for(int i = 1; i < n; ++i) {

            int profit = prices[i] - minPrice;

            maxProfit = max(profit, maxProfit);

            if(minPrice > prices[i]) minPrice = prices[i];
        }

        return maxProfit;
    }
};
