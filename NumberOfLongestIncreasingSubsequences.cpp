class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int N = nums.size();
        int * memo = new int[N];
        int * count = new int[N];
        for (int i = 0; i < N; i++){
            memo[i] = 1;
            count[i] = 1;
        }
        int max_length = 1;
        for (int i = 1; i < N; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    if (memo[j] +1 > memo[i]){
                        memo[i] = memo[j]+1;
                        count[i] = count[j];
                    }
                    else if (memo[j]+1 == memo[i]){
                        count[i] += count[j];
                    }
                }
                
            }
            max_length = max(max_length,memo[i]);
        }
        int answer = 0;
        for (int i = 0 ; i < N; i++){
            if (memo[i] == max_length) answer +=count[i];
        }
        return answer;
    }
};
