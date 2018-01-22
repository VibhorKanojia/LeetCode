class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if (N == 0 || N == 1) return 0;
        int profit[N][2];
        profit[0][1] = -prices[0];
        profit[0][0] = 0;
        profit[1][1] = -min(prices[0], prices[1]);
        profit[1][0] = max(0, -prices[0]+prices[1]);
        
        for (int i = 2; i < N; i++){
            profit[i][1] = max(profit[i-2][0]-prices[i], profit[i-1][1]);
            profit[i][0] = max(profit[i-1][1]+prices[i], profit[i-1][0]);
        }
        return profit[N-1][0];
    }
};
