class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0) return;
        int zeroIndex = 0;
        int nonzeroIndex = 0;
        while(nonzeroIndex < nums.size()){
            while (nums[zeroIndex] != 0 && zeroIndex < nums.size()) zeroIndex++;
            while (nums[nonzeroIndex] == 0 && nonzeroIndex < nums.size()) nonzeroIndex++;
            if (zeroIndex >= nums.size() || nonzeroIndex >= nums.size()) return;
            if (zeroIndex < nonzeroIndex){
                nums[zeroIndex] = nums[nonzeroIndex];
                nums[nonzeroIndex] = 0;
            }
            else{
                nonzeroIndex++;
            }
        }
        return;
    }
};
