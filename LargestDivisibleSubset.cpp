//O(N^2) solution. Really good question
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        if (n == 0) return result;
        sort(nums.begin(), nums.end());
        vector<int> dp(n,0);
        vector<int> pre(n,0);
        dp[0] = 1;
        pre[0] = -1;
        int maxLen = -1;
        int lastIndex = 0;
        for (int i = 1; i < n; i++){
            dp[i] = 1;
            pre[i] = -1;
            for (int j = 0; j < i; j++){
                if (nums[i] % nums[j] == 0 && dp[i] < 1+dp[j]){
                    dp[i] = 1+dp[j];
                    pre[i] = j;
                }
            }
            if (maxLen < dp[i]){
                maxLen = dp[i];
                lastIndex = i;
            }
        }
        stack<int> buffer;
        while (lastIndex != -1){
            buffer.push(lastIndex);
            lastIndex = pre[lastIndex];
        }
        while (!buffer.empty()){
            result.push_back(nums[buffer.top()]);
            buffer.pop();
        }
        return result;
    }
};
