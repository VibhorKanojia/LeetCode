class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int count = INT_MAX;
        queue<int> buffer;
        int csum = 0;
        for (int i = 0 ; i < nums.size(); i++){
            csum += nums[i];
            buffer.push(nums[i]);
            while(csum >= s){
                count = (count < buffer.size())?count:buffer.size();
                int elem = buffer.front();
                csum -= elem;
                buffer.pop();
            }
        }
        return (count == INT_MAX)?0:count;
    }
};
