class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return n;
        
        int ** dp = new int*[n];
        for (int i =0 ; i < n ; i++){
            dp[i] = new int[n];
        }
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                dp[i][j] = -1;
            }
            dp[i][i] = 1;
        }
        
        for (int i = 0 ; i < n-1; i++){
            if (s[i] == s[i+1]) dp[i][i+1] = 1;
        }
        
        for (int i = n-1 ; i >= 0 ; i--){
            for (int j = i ; j < n ; j++){
                if (dp[i][j] == -1 && s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1]; 
                }
            }
        }
        
        int count = 0;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0; j < n ; j++){
                count += (dp[i][j] == 1)?1:0;    
            }
        }
        
        return count;
        
    }
};
