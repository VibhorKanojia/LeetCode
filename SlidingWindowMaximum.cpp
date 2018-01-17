class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> array;
        int n = nums.size();
        if (n == 0) return array;
        deque<int> buffer; // we will store the indices of the elements;
        int i = 0;
        while (i < k){
            int cur_elem = nums[i];
            while ((!buffer.empty()) && cur_elem >= nums[buffer.back()]) buffer.pop_back();
 
            buffer.push_back(i);
            i++;
        }

        while (i < n){
            int cur_elem = nums[i];
            array.push_back(nums[buffer.front()]);
            //popping elements out of the window
            while ((!buffer.empty()) && buffer.front() <= i-k) buffer.pop_front();
            while ((!buffer.empty()) && cur_elem >= nums[buffer.back()]) buffer.pop_back();
            buffer.push_back(i);
            i++;
        }    
        array.push_back(nums[buffer.front()]);
        return array;
    }
};
