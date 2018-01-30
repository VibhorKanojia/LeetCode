//Classic Question
class Solution {
private:
    //Key here is to note that mid elem is compared with end elem for binary search.
    int findPivot(vector<int> & nums, int start, int end){
        if (start == end) return start;
        int mid = start + (end-start)/2;
        if (nums[mid] > nums[end]) return findPivot(nums, mid+1,end);
        else return findPivot(nums,start,mid);
    }
    //note the use of mod; be VERY careful while coding this
    int binarySearch(vector<int> & nums, int pivot, int start, int end, int target){
        int n = nums.size();
        if (start > end) return -1;
        int mid = start + (end-start)/2;
        if (nums[mid%n] == target) return mid%n;
        if (nums[mid%n] > target) return binarySearch(nums,pivot,start,mid-1,target);
        else return binarySearch(nums, pivot, mid+1, end, target);
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
        if (n == 0) return -1;
        int k = findPivot(nums, 0, n-1); 
        return binarySearch(nums, k, k, n+k-1,target);
    }
};
