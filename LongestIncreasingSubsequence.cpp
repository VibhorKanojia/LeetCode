class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return 1;
        int *dp = new int[size];
        dp[0]=1;
        int maxSeq = 0;
        for (int i = 1 ; i < size ; i++){
            dp[i] = 1+findSeq(i,dp,nums);
            if (maxSeq < dp[i]) maxSeq = dp[i];
        }
        return maxSeq;
        
        
    }
    int findSeq(int curInd, int * dp, vector<int>& nums){
        int maxLen = 0;
        for (int i = 0 ; i < curInd ; i++){
            if (nums[i] < nums[curInd] && maxLen < dp[i]){
                maxLen = dp[i];
            }
        }
        return maxLen;
    }
};
