class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0 || size == 1) return 0;
        int profit = 0;
        for (int i=1; i < size; i++){
            if (prices[i] - prices[i-1] > 0){
                profit +=prices[i] - prices[i-1];
            }
        }
        
        return profit;
    }
};
