class Solution {
private:
    int binarySearch(vector<int> & nums, int target, int s, int e, int flag){
        if (flag == 1){
            if (s > e) return INT_MAX;
            int mid = e - (e-s)/2;
            if (nums[mid] == target){
                return min(mid, binarySearch(nums, target, s, mid-1, flag));
            }
            else if (nums[mid] > target){
                return binarySearch(nums, target, s, mid-1, flag);
            }
            else{
                return binarySearch(nums, target, mid+1, e, flag);
            }
        }
        else{
            if (s > e) return INT_MIN;
            int mid = e - (e-s)/2;
            if (nums[mid] == target){
                return max(mid, binarySearch(nums, target, mid+1, e, flag));
            }
            else if (nums[mid] > target){
                return binarySearch(nums, target, s, mid-1, flag);
            }
            else{
                return binarySearch(nums, target, mid+1, e, flag);
            }
        }
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left_index = binarySearch(nums, target, 0, n-1, 1);
        int right_index = binarySearch(nums, target, 0, n-1, 2);
        if (left_index == INT_MAX) {
            left_index = -1;
            right_index = -1;
        }     
        vector<int> result;
        result.push_back(left_index);
        result.push_back(right_index);
        return result;
    }
};
