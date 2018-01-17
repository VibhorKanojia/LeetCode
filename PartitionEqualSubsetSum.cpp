class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int size = nums.size();
        if (size == 1) return false;
        int sum = 0;
        for (int i = 0 ; i < size ; i++){
            sum +=nums[i];
        }
        if (sum % 2 != 0) return false;
        
        for (int i = 0 ; i< size ;i++){
            bits |= bits << nums[i];
        }
        return bits[sum/2];
    }
};
