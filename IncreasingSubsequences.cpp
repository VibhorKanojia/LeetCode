class Solution {
private:
    void backTrack(vector<int> & nums, int index, vector<vector<int>>& result, vector<int> & sequence){
        if (sequence.size() > 1) result.push_back(sequence);
        unordered_map<int, bool> mapper; 
        for (int i = index; i < nums.size(); i++){
            if ((sequence.size() == 0 || nums[i] >= sequence.back()) && mapper.find(nums[i]) == mapper.end()){ 
                sequence.push_back(nums[i]);
                backTrack(nums,i+1,result,sequence);
                sequence.pop_back();
                mapper.insert(pair<int,bool>(nums[i],true));
            }
        }
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        vector<int> sequence;
        backTrack(nums,0, result, sequence);
        return result;
    }
};
