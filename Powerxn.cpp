class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        double val = myPow(x,n/2);
        double answer;
        
        answer = val*val;
        
        
        if (abs(n)%2 == 1){
            if (n < 0) answer = answer/x;
            else answer = answer*x;
        }
    
        return answer;
    }
};
