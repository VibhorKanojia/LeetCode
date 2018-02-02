class Solution {
private:
    int findPivot(vector<int> & nums, int start, int end){
        
        if (start == end) return start;
        int mid = start + (end-start)/2;
        if (nums[mid] > nums[end]) return findPivot(nums,mid+1,end);
        else return findPivot(nums,start, mid);
    }
    
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int k = findPivot(nums, 0, n-1);
        return nums[k];
    }
};
