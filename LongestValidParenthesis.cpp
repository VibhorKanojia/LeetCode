class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        if (size == 1 || size == 0) return 0;
        int dp[size+1];
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 0 ; i <= size ; i++){
            dp[i] = 0;
        }
        
        for (int i = 2 ; i <= size ; i++){
            if (s[i-1] == ')'){
                if (s[i-2] == '('){
                    dp[i] = dp[i-2]+2;
                }
                else if (s[i-2] == ')'){
                    int index = i-1 - dp[i-1] - 1;
                    if (index < 0) {
                        dp[i] = 0;
                        continue;
                    }
                    else if (s[i-1 - dp[i-1]-1] == '('){
                        dp[i] = 2+dp[i-1]+dp[index];
                    }
                }
            }
        }
        int maxElem = 0;
        for (int i = 0 ; i <= size ; i++){
            maxElem = max(maxElem, dp[i]);
        }

        
        return maxElem;
    
    }
};
