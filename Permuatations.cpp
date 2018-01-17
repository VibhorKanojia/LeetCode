class Solution {
private:
    void backtrack(vector<int> & nums, vector<vector<int>> & solution, unordered_set<int> & mapper, vector<int> permutation){
        if (permutation.size() == nums.size()){
            solution.push_back(permutation);
            return;
        }
        for (int i = 0 ; i < nums.size(); i++){
            if (mapper.find(nums[i]) != mapper.end()) continue;
            mapper.insert(nums[i]);
            permutation.push_back(nums[i]);
            backtrack(nums,solution,mapper,permutation);
            mapper.erase(nums[i]);
            permutation.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution;
        if (nums.size() == 0) return solution;
        unordered_set<int> mapper;
        vector<int> permutation;
        backtrack(nums,solution,mapper,permutation);
        return solution;
    }
};
