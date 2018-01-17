//https://leetcode.com/problems/find-peak-element/description/

class Solution {
private:
    int binarySearch(vector<int> & nums, int start ,int end){
        if (start == end) return start;
        int mid = start + (end-start)/2;
        if (nums[mid] > nums[mid+1]) return binarySearch(nums, start, mid);
        else return binarySearch(nums,mid+1,end);
    }
public:
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums,0,nums.size()-1);   
    }
};
