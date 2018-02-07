//Excellent Solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        if (n == 0) return result;
        int before = 1;
        for (int i =0 ; i < n ; i++){
            result[i] = before;
            before *= nums[i];
        }
        int after = 1;
        for (int i =n-1 ; i >= 0  ; i--){
            result[i] *= after;
            after *= nums[i];
        }
        return result;
    }
};
