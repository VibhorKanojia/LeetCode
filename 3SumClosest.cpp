class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        long int closest = INT_MAX;
        for (int i =0 ; i < n; i++){
            int a = nums[i];
            int low = i+1;
            int high = n-1;
            while (low < high){
                long int val = a + nums[low]+nums[high];
                closest = (abs((long)target-closest) > abs((long)target-val))? val: closest;
                if (val < target) low++;
                else if (val > target) high--;
                else break;
            }
        }
        return closest;
    }
};
