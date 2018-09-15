//Can be optimized to be O(N) space.
class Solution {
private:
    int stoneGameHelper(vector<int> & piles, int ** memo, int s, int t){
        if (s > t) return 0;
        if (memo[s][t] != INT_MAX) return memo[s][t];
        memo[s][t] = max(piles[s] - stoneGameHelper(piles, memo, s+1, t), piles[t] - stoneGameHelper(piles,memo,s,t-1));
        return memo[s][t];
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int ** memo = new int*[n];
        for (int i =0 ; i < n; i++){
            memo[i] = new int[n];
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n ; j++){
                memo[i][j] = INT_MAX;
            }
        }
        
        return stoneGameHelper(piles, memo, 0, n-1) > 0;
    }
};
