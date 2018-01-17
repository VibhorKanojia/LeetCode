class Solution {
private:
    bool canPlace(int x, int y, vector<int> & placement){
        int n = placement.size();
        for (int i = 0 ; i < x ; i++){
            if (placement[i]  == y) return false;
        }

        
        int i = x;
        int j = y;
        while (i >= 0 && j >= 0){
            if (placement[i] == j) return false;
            i--;
            j--;
        }
        i = x;
        j = y;
        while (i >= 0 && j < n){
            if (placement[i] == j) return false;
            i--;
            j++;
        }
        return true;
    }
    
    vector<string> generateString(vector<int> & placement){
        int n = placement.size();
        vector<string> result;
        for (int i = 0 ; i < n ; i++){
            string str = "";
            for (int j = 0; j < n; j++){
                if (j == placement[i]) str +="Q";
                else str+=".";
            }
            result.push_back(str);
        }
        return result;
    }
    
    void backtrack(int n, vector<int> & placement, vector<vector<string>> & solution){
        int size = placement.size();
        if (n == 0){
            vector<string> elem = generateString(placement);
            solution.push_back(elem);
            return;
        }
        for (int index = 0; index < size; index++){
            if (canPlace(size-n,index,placement)){
                placement[size-n] = index;
                backtrack(n-1,placement, solution);
                placement[size-n] = -1;
            }
        }
        return;
    }
    
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solution;
        if (n == 0) return solution;
        vector<int> placement(n, -1);
        
       
        backtrack(n, placement, solution);
       
        return solution;
    }
};
