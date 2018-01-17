class Solution {
private:
    void backtrack(vector<int> & candidates, int target, vector<vector<int>>& solution, vector<int> & subset,int index){
        int n = candidates.size();
        if (target < 0) return;
        if (target == 0){
            solution.push_back(subset);
            return;
        }
        if (index >=n) return;
        for (int i = index ; i < n; i++){
            subset.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i],solution,subset,i);
            subset.pop_back();
        }
        
        return;
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solution;
        int n = candidates.size();
        if (n == 0) return solution;
        vector<int> subset;
        backtrack(candidates,target,solution, subset,0);
        return solution;
    }
};
