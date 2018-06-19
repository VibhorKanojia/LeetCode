class Solution {
private:
    int binarySearch(vector<int> & nums, int start, int end){
        if (start == end) return nums[start];
        int mid = start + (end-start)/2;
        if (mid%2 == 0){
            if (nums[mid] == nums[mid+1]) return binarySearch(nums, mid+2, end);
            else return binarySearch(nums, start, mid);
        }
        else{
            if (nums[mid] == nums[mid-1]) return binarySearch(nums, mid+1, end);
            else return binarySearch(nums,start, mid-1);
        }
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size();
        return binarySearch(nums, 0, N-1);
    }
};
