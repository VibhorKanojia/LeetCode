class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n==0 || n==1) return n;
        int flag = -1;
        int count = 1;
        for (int i = 1; i < n ; i++){
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] > nums[i-1] && flag != 0){
                flag= 0; //increasing
                count++;
                continue;
            }
            if (nums[i] < nums[i-1] && flag != 1){
                flag = 1; //decreasing
                count++;
                continue;
            }
        }
        return count;
    }
};
