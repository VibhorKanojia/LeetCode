class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int T[n][3][2];
        
        for (int i = 0 ; i < n ; i++){
            T[i][0][0] = 0;
            T[i][0][1] = -INT_MAX;
        }
        T[0][1][0] = 0;
        T[0][2][0] = 0;
        T[0][1][1] = -prices[0];
        T[0][2][1] = -prices[0];
        
        for (int i=1 ; i < n ; i++){
            T[i][2][0] = max(T[i-1][2][0], T[i-1][2][1] + prices[i]);
            T[i][2][1] = max(T[i-1][2][1], T[i-1][1][0] - prices[i]);
            T[i][1][0] = max(T[i-1][1][0], T[i-1][1][1] + prices[i]);
            T[i][1][1] = max(T[i-1][1][1], T[i-1][0][0] - prices[i]);
        }
        
        return T[n-1][2][0];
    }
};
