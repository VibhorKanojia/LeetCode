class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        if (size == 0) return 0;
        if (size == 1) return 1;
        int ** dp = new int*[size];
        for (int i = 0 ; i < size ; i++){
            dp[i] = new int[size];
        }
        
        for (int i = 0 ; i < size ; i++){
            for (int j = 0 ; j < size ; j++){
                dp[i][j] = 0;
            }
            dp[i][i] = 1;
        }
        
        for (int i = size -1 ; i >= 0 ; i--){
            for (int j = i+1; j < size ; j++){
                if (s[i] == s[j]){
                 dp[i][j] = dp[i+1][j-1] +2;   
                } 
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][size-1];
    }
};
