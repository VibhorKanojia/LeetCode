class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<int> memo(A.size(),0);
        int count = 0;
        for (int i = 2; i < A.size(); i++){
            if (A[i]- A[i-1] == A[i-1] - A[i-2]){
                memo[i] = memo[i-1]+1;
            }
            count +=memo[i];
        }
        return count;
    }
};
