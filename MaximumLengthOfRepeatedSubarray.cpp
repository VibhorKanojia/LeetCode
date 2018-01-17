class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int N = A.size();
        int M = B.size();
        int ** memo = new int*[N+1];
        for (int i = 0 ; i < N+1 ; i++){
            memo[i] = new int[M+1];
        }
        for (int i = 0 ; i <= N; i++){
            for (int j = 0 ; j <= M; j++){
                memo[i][j] = 0;
            }
        }
        int max_val = 0;
        for (int i = 1 ; i <= N; i++){
            for (int j = 1 ; j <= M; j++){
                if (A[i-1] == B[j-1]) memo[i][j] = 1+ memo[i-1][j-1];
                max_val = max(max_val, memo[i][j]);
            }
        }
        
        return max_val;
    }
};
