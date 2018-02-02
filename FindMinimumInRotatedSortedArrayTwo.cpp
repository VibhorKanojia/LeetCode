class Solution {
private:
    int findPivot(vector<int> & nums, int start, int end){
        if (start == end) return start;
        int mid = start + (end-start)/2;
        if (nums[mid] > nums[end]) return findPivot(nums,mid+1,end);
        else if (nums[mid] < nums[end]) return findPivot(nums,start,mid);
        else{
            while(start < end && nums[start] == nums[start+1]) start++;
            while(end > start && nums[end] == nums[end-1]) end--;
            return findPivot(nums,start,end);
        }
    }
    
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int k = findPivot(nums,0,n-1);
        return nums[k];
    }
};
