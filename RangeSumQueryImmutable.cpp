class NumArray {
private:
    vector<int> csum;
    vector<int> nums;

public:
    NumArray(vector<int> nums) {
        this->nums = nums;
        int sum = 0;
        for (int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            csum.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return (csum[j]-csum[i]+nums[i]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
