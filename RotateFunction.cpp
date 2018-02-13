class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        int maxval = 0;
        int sum = 0;
        for (int i =0 ; i < n; i++){
            maxval += i*A[i];
            sum += A[i];
        }
        int curval = maxval;
        for (int i = n-1; i>=0 ; i--){
            curval = curval + sum - n*A[i];
            maxval = max(curval, maxval);
        }
        return maxval;
    }
};
