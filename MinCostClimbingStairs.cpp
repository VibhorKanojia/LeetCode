class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0 || n == 1) return 0;
        vector<int> cummCost(n,0);
        cummCost[0] = cost[0];
        cummCost[1] = cost[1];
        for (int i = 2 ; i < n; i++){
            cummCost[i] = cost[i] + min(cummCost[i-1], cummCost[i-2]);
        }
        
        return min(cummCost[n-1], cummCost[n-2]);
    }
};
