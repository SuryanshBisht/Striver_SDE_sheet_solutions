class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = prices.back(), profit = 0;
        for(int i = prices.size()  - 1; i >= 0  ;i--){
            profit = max(profit, mx - prices[i]);
            if(prices[i] > mx){
                mx = prices[i];
            }
        }
        
        return profit;
    }
}; // faster possible?