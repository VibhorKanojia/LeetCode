class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int N = nums.size();
        int i = 0;
        while(i < N){
            if (nums[i] >= N) i++;
            else if (nums[nums[i]] == nums[i]) i++;
            else{
                int temp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = temp;
            }
        }
        for (int i = 0 ; i < N ; i++){
            if (nums[i] != i) return i;
        }
        return N;
    }
};
