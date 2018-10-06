class Solution {
private:
    int findPivot(vector<int> & nums, int start, int end){
        if (start == end) return start;
        int mid = start+(end-start)/2;
        if (nums[mid] < nums[end]) return findPivot(nums, start, mid);
        else return findPivot(nums, mid+1, end);
    }
    
    int binarySearch(vector<int> & nums, int start, int end, int target){
        int n = nums.size();
        if (start > end) return -1;
        int mid = end - (end - start)/2;
        if (nums[mid%n] == target) return mid%n;
        if (nums[mid%n] < target) return binarySearch(nums, mid+1, end, target);
        else return binarySearch(nums, start, mid-1, target);
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
        if (n == 0) return -1;
        int k = findPivot(nums, 0, n-1); 
        //Note that offset is only needed to initialize start and end
        return binarySearch(nums, k, n+k-1, target);
    }
};
