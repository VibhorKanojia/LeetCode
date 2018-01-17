class Solution {
public:
    int numSquares(int n) {
        int * dp = new int[n+1];
        for (int i = 0 ; i < n+1; i++){
            dp[i] = 0;
        }
        for (int i = 1 ; i*i < n+1 ; i++){
            dp[i*i] = 1;
        }
        
        for (int i = 2; i < n+1 ; i++){
            if (!dp[i]){
                int j = 1;
                dp[i] = INT_MAX;
                while(j*j <= i){
                    dp[i] = min(dp[i], 1 + dp[i-j*j]);
                    j++;
                }
            }
        }
        
        return dp[n];
    }
};
