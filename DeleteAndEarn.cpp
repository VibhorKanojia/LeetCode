class Solution {
private:
    int dpFunction(int * cArray, int * memo, int start){
        if (start >= 10000) return 0;
        if (memo[start] != -1) return memo[start];
        memo[start] = max(dpFunction(cArray, memo, start+1), start*cArray[start] + dpFunction(cArray,memo,start+2));
        return memo[start];
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int * cArray = new int[10001];
        int * memo = new int[10001];
        for (int i = 0 ; i < 10001; i++) {
            cArray[i] = 0;
            memo[i] = -1;
        }
        for (int i = 0 ; i < nums.size(); i++) cArray[nums[i]]++;
        
        int answer = dpFunction(cArray, memo, 0);
        return answer;
    }
};
