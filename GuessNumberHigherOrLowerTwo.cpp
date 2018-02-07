//Don't judge a book by its cover. Really good question.
class Solution {
private:
    int fillDP(int ** dp, int start, int end){
        if (start > end) return -1;
        if (dp[start][end] != INT_MAX) return dp[start][end];
        if (start == end-1){
            dp[start][end] = start;
            return dp[start][end];
        }
        for (int k =start; k <=end; k++){
            dp[start][end] = min(dp[start][end], k+max(fillDP(dp,start,k-1), fillDP(dp,k+1,end)));
        }
        return dp[start][end];
    }
public:
    int getMoneyAmount(int n) {
        if (n == 1) return 0;
        int ** dp = new int*[n+1];
        for (int i =0 ; i < n+1; i++){
            dp[i] = new int[n+1];
        }
        for (int i = 0; i < n+1; i++){
            for (int j = 0 ; j < n+1; j++){
                dp[i][j] = INT_MAX;
            }
            dp[i][i] = 0;
        }
        
        int answer = fillDP(dp,1,n);
        return answer;
    }
};
