class Solution {
public:
    int changeHelper(int amount, vector<int> & coins, int index, int ** memo){
        if (index >= coins.size()) return 0;
        if (amount < 0) return 0;
        if (amount == 0) return 1;
        if (memo[amount][index] != -1) return memo[amount][index];
        memo[amount][index] = changeHelper(amount-coins[index], coins, index, memo) + changeHelper(amount, coins, index+1, memo);
        return memo[amount][index];
    }
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        if (coins.size() == 0) return 0;
        
        int n = coins.size();
        int ** memo = new int*[amount+1];
        for (int i = 0 ; i < amount+1 ; i++){
            memo[i] = new int[n];
        }
        
        for (int i = 0 ; i < amount+1; i++){
            for (int j = 0 ; j < n ; j++){
                memo[i][j] = -1;
            }
        }
        return changeHelper(amount, coins, 0, memo);
    }
};
