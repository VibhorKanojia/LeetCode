class Solution {
private:
    void backtrack(vector<int> & candidates, int target, vector<vector<int>>& solution, vector<int> & subset,int index, unordered_set<int> myset){
        int n = candidates.size();
        if (target < 0) return;
        if (target == 0){
            solution.push_back(subset);
            return;
        }
        if (index >=n) return;
        for (int i = index ; i < n; i++){
            if (myset.find(candidates[i]) != myset.end()) continue;
            subset.push_back(candidates[i]);
            //We want the following calls of backtrack to have the current myset. But we don't want the current myset to be changed in the following calls. So we pass myset by value and not by reference. Because that will ensure that the changes made in myset will be limited to the scope of that call.
            backtrack(candidates, target-candidates[i],solution,subset,i+1,myset);
            myset.insert(candidates[i]);
            subset.pop_back();
        }
        
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> solution;
        int n = candidates.size();
        if (n == 0) return solution;
        vector<int> subset;
        unordered_set<int> myset;
        backtrack(candidates,target,solution, subset,0,myset);
        return solution;
    }
};
