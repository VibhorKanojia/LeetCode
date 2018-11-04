class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int max_till_i_minus_2 = INT_MIN;
        for (int i = 2; i < A.size(); i++){
            max_till_i_minus_2 = max(max_till_i_minus_2, A[i-2]);
            if (A[i] < max_till_i_minus_2) return false;
         }
        return true;
    }
};
