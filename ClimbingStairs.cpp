class Solution {
public:
    int climbStairs(int n) {
        int count[n+1];
        count[0] =1;
        count[1] =1;
        for (int i = 2 ; i < n+1 ; i++){
            count[i] = count[i-1]+count[i-2];
        }
        return count[n];
    }
    
};
