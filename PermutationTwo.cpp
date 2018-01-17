class Solution {
private:
    void backtrack(vector<int> & nums, vector<vector<int>> & solution, unordered_set<int> & mapper, vector<int> permutation){
        if (permutation.size() == nums.size()){
            solution.push_back(permutation);
            return;
        }
        unordered_set<int> dupMapper;
        for (int i = 0 ; i < nums.size(); i++){
            if (mapper.find(i) != mapper.end()) continue;
            if (dupMapper.find(nums[i]) != dupMapper.end()) continue;
            permutation.push_back(nums[i]);
            mapper.insert(i);
            backtrack(nums,solution,mapper,permutation);
            mapper.erase(i);
            dupMapper.insert(nums[i]);
            permutation.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> solution;
        if (nums.size() == 0) return solution;
        unordered_set<int> mapper;
        vector<int> permutation;
        backtrack(nums,solution,mapper,permutation);
        return solution;
    }
};
