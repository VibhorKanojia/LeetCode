class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mapper;
        unordered_map<int,int>::iterator it;
        int count = 0;
        int max_len = 0;
        mapper.insert(pair<int,int>(0,-1));
        for (int i = 0 ; i < n; i++){
            if (nums[i] == 1) count++;
            else count --;
            it = mapper.find(count);
            if (it != mapper.end()) max_len = max(max_len, i - it->second);
            else mapper.insert(pair<int,int>(count,i));
        }
        return max_len;
    }
};
