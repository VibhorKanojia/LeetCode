class Solution {
public:
    int singleNumber(int A[], int n) {
        int myxor = A[0];
        for (int i = 1 ; i < n ; i++){
            myxor = myxor^A[i];
        }
        return myxor;
    }
};
