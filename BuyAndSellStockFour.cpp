class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (size == 0 || size == 1) return 0;
        if (k > size/2){
            int profit = 0;
            for (int i = 1; i< size; i++){
                profit += max(prices[i] - prices[i-1],0);
            }
            return profit;
        }
        
        int release[k+1];
        int hold[k+1];
        
        for (int i = 0 ; i <= k ; i++){
            release[i] = 0;
            hold[i] = INT_MIN;
        }
        for (int i = 0 ; i < size ; i++){
            for (int j = 1 ; j <= k; j++){
                hold[j] = max(hold[j], release[j-1]-prices[i]);
                release[j] = max(release[j], hold[j]+prices[i]);
            }
        }
        return release[k];    
    }
};

