//p+s = sum
//p-s = target
//p-(sum-p) = target
//2p = target+sum
//p=(target+sum)/2

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        int sum = 0;
        for (int i = 0 ; i < size ; i++){
            sum +=nums[i];
        }
        if ((S+sum)%2 != 0) return 0;
        if (S > sum) return 0;
        
        int psum = (S+sum)/2;
        
        int dp[sum+1];
        for (int i = 0 ; i <= sum ; i++) dp[i] = 0;
        dp[0] =1;
        for (int i = 0 ; i < size ; i++){
            for (int j = sum ; j-nums[i] >=0 ; j--){
                dp[j] +=dp[j-nums[i]];
            }
        }
        
        return dp[psum];
        
        
        
    }
};
