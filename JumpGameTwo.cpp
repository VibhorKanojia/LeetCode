//https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return 0;
        
        int steps = 0;
        int currentMax = 0; //Maximum index reachable at current level;
        int nextMax = 0; //Maximum index reachable at next level; 
        int i = 0;
        while (i < n){
            steps++;
            while (i<=currentMax){ // traverse all elems in the current level;
                nextMax = max(nextMax, i+nums[i]); //Update next max index
                if (nextMax >= n-1) return steps; //We can reach the last element;
                i++;
            }
            if (currentMax == nextMax) break;
            currentMax = nextMax;
        }
        return -1; //cannot reach
    }
};
