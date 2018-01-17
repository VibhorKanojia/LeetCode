class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n ==0) return 0;
        int dp[n+1];
        dp[0] = 1;
        if (s[0] == '0') return 0; 
        dp[1] = 1;
        for (int i = 2; i < n+1 ; i++){
            if (s[i-1] == '0'){
                if (s[i-2] !='1' and s[i-2] != '2') return 0;
                else dp[i] = max(1,dp[i-2]);
            }
            else if (s[i-2] == '0') dp[i] = dp[i-1];
            else if (s[i-2] == '1') dp[i]  = dp[i-1] + dp[i-2];
            else if (s[i-2] == '2' && s[i-1] <='6') dp[i] = dp[i-1] + dp[i-2];
            else if (s[i-2] == '2' && s[i-1] > '6') dp[i] = dp[i-1];
            else if (s[i-2] > '2') dp[i] = dp[i-1];
        }
        
        return dp[n];
    }
};
