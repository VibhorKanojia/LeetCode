class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1 || K == 1) return 0;
        int num_elems = pow(2,N-1);
        
        int val = kthGrammar(N-1, (K <= num_elems/2)? K : K-num_elems/2);
        
        if (K <= num_elems/2) return val;
        else return (val+1)%2;
    }
};
