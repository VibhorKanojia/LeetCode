class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int N = nums.size();
        int maxVal = INT_MAX;
        int first;
        int maximum;
        int flag = 0;
        for (int i = 0 ;  i < 3 ; i++){
            maximum = INT_MIN;
            for (int j = 0; j < N ; j++){
                if (nums[j] >= maximum && nums[j] < maxVal){
                    if (i == 2) flag =1;
                    maximum = nums[j];
                }
            }
            if (i == 0) first = maximum;
            maxVal = maximum;
        }
        if (flag == 0) return first;
        else return maximum;
    }
};
