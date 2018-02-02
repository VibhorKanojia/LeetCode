//REALLY GOOD QUESTION
class Solution {
private:
    int mergeSort(vector<long int>& nums, int lower, int upper, int start, int end){
        if (start >= end) return 0;
        if (start == (end -1)){
            if (nums[start] >= lower && nums[start] <= upper) return 1;
            else return 0;
        }
        int count = 0;
        int mid = start + (end-start)/2;
        count += mergeSort(nums, lower, upper, start, mid) + mergeSort(nums, lower, upper, mid, end);
        int l = mid;
        int u = mid;
        for (int i = start ; i < mid ; i++){
            while (l < end && nums[l] - nums[i] < lower) l++; 
            while (u < end && nums[u] - nums[i] <= upper) u++;
            count += u-l; //Numbers between l to u satisfy the condition. Note that we do not have to re-initialized l and u for the next i. 
        }
        inplace_merge(nums.begin()+start, nums.begin()+mid, nums.begin()+end); //REALLY GOOD UTILITY FUNCTION
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) return 0;
        vector<long int> sums; //test cases contain INT_MAX values
        sums.push_back(nums[0]);
        for (int i = 1; i < nums.size() ; i++){
            sums.push_back(sums[i-1]+nums[i]);
        }
        return mergeSort(sums, lower, upper, 0, sums.size()); //keeping end exclusive for the inplace_merge function
    }
};
