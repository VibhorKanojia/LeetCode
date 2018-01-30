//CLASSIC QUESTION
class Solution {
private:
    int findPivot(vector<int> & nums, int start, int end){
        if (start == end) return start;
        int mid = start + (end-start)/2;
        if (nums[mid] > nums[end]) return findPivot(nums,mid+1,end);
        else if (nums[mid] < nums[end]) return findPivot(nums, start, mid);
        else{
            //GOLDEN STEP
            while (start < end && nums[start] == nums[start+1]) start++;
            while (end > start && nums[end] == nums[end-1]) end--;
            return findPivot(nums,start,end);
        }
    }
    
    bool binarySearch(vector<int> & nums, int start, int end, int target){
        int n = nums.size();
        if (start > end) return 0;
        int mid = start + (end-start)/2;
        if (nums[mid%n] == target) return 1;
        else if (nums[mid%n] > target) return binarySearch(nums, start, mid-1, target);
        else return binarySearch(nums,mid+1,end,target);
    }
    
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==0) return 0;
        int k = findPivot(nums, 0, n-1);
        cout<<k<<endl;
        return binarySearch(nums, k, n+k-1, target);
    }
};
