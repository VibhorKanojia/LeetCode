class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return true;
        
        int i = 0;
        int curMax = 0;
        while(i<=curMax){
            curMax = max(curMax, i+nums[i]);
            if (curMax >= n-1) return true;
            i++;
            
        }
        return false;
    }
};
