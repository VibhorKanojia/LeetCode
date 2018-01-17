//https://leetcode.com/problems/maximum-gap/description/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() < 2) return 0;
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (int i = 0 ; i < nums.size(); i++){
            min_val = min(min_val, nums[i]);
            max_val = max(max_val, nums[i]);
        }
        int gap = ceil((float)(max_val - min_val)/(n-1));
        vector<int> bucketsMIN(n-1,INT_MAX);
        vector<int> bucketsMAX(n-1,INT_MIN);
        for (int i=0; i < nums.size(); i++){
            if (nums[i] == min_val || nums[i] == max_val) continue;
            int index = (nums[i] - min_val)/gap;
            bucketsMIN[index] = min(bucketsMIN[index], nums[i]);
            bucketsMAX[index] = max(bucketsMAX[index], nums[i]);
        }
        int pre_val = min_val;
        int answer = 0;
        for (int i = 0 ; i < bucketsMIN.size(); i++){
            if (bucketsMIN[i] == INT_MAX && bucketsMAX[i] == INT_MIN) continue;
            answer = max(answer, bucketsMIN[i] - pre_val);
            pre_val = bucketsMAX[i];
        }
        answer = max(answer, max_val - pre_val);
        return answer;
    }
};
