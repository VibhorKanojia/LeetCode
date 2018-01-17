class Solution {
private:
    vector<int> nums;
    
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int count = 1;
        int index = 0;
        for (int i = 0 ; i < nums.size(); i++){
            if (nums[i] != target) continue;
            int randVal = rand()%count;
            if (randVal == 0) index = i;
            count++;
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
