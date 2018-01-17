class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int ans = INT_MIN;
        int front = 0;
        int back = 0;
        for (int i=0; i<n; i++) {
            front = front ? front*nums[i] : nums[i];
            back = back ? back*nums[n-1-i] : nums[n-1-i];
            ans = max(ans, max(front, back));
        }
        return ans;
    }
};

