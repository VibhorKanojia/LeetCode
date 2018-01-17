class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int dp[size];
        dp[0] = nums[0];
        int max = nums[0];
        int index[size];
        index[0] = 0;
        for (int i = 1 ; i < size ; i++){
            dp[i] = (nums[i]+dp[i-1] > nums[i])?nums[i]+dp[i-1]:nums[i];
            if (dp[i] > max){
                max = dp[i];
            }
        }
        return max;
    }
};
