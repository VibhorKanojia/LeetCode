class Solution {
private:
    int PredictHelper(vector<int> & nums, int start, int end, int ** memo){
        if (start == end) return nums[start];
        if (memo[start][end] != -1) return memo[start][end];
        memo[start][end] = max((nums[start]-PredictHelper(nums,start+1,end,memo)), (nums[end] - PredictHelper(nums,start,end-1,memo)));
        return memo[start][end];
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int ** memo = new int*[n];
        for (int i = 0; i < n; i++){
            memo[i] = new int[n];
        }
        for (int i = 0 ; i < n ; i++){
            for (int j = 0; j < n ; j++){
                memo[i][j]= -1;
            }
        }
        int answer = PredictHelper(nums,0, nums.size()-1, memo);
        //cout<<answer<<endl;
        if (answer >=0) return true;
        else return false;
    }
};
