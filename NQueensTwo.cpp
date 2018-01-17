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
      
    void backtrack(int n, vector<int> & placement, int & count){
        int size = placement.size();
        if (n == 0){
            count++;
            return;
        }
        for (int index = 0; index < size; index++){
            if (canPlace(size-n,index,placement)){
                placement[size-n] = index;
                backtrack(n-1,placement, count);
                placement[size-n] = -1;
            }
        }
        return;
    }
    
    
    
public:
    int totalNQueens(int n) {
        int count = 0;
        if (n == 0) return count;
        vector<int> placement(n, -1);
        backtrack(n, placement, count);
       
        return count;  
    }
};
