class Solution {
private:
    int fillArray(unordered_map<int,int> & memo, long int n){
        if (memo.find(n) != memo.end()) return memo[n];
        int minval = INT_MAX;
        if (n %2 == 0){
            memo[n] = 1+fillArray(memo,n/2);
        }
        else{
            memo[n] = min(1+fillArray(memo,n-1), 1+fillArray(memo,n+1));
        }
        
        return memo[n];
    }
    
public:
    int integerReplacement(int n) {
        unordered_map<int,int> memo;
        memo[1] = 0;
        fillArray(memo, n);
        return memo[n];
    }
};
