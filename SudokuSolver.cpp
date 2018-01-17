class Solution {
private:
    bool canPlaceinBox(char c, vector<vector<char>>&board, int bx,int by){
        for (int i = bx*3; i < bx*3+3; i++){
            for (int j = by*3; j < by*3+3; j++){
                if (board[i][j] == c) return false;
            }
        }
        return true;
    }
    
    bool canPlace(char c, vector<vector<char>>&board, int x, int y){
        for (int i = 0 ; i < 9 ; i++){
            if (board[i][y] == c) return false;
            if (board[x][i] == c) return false;
        }    
        int blockX = (int)(x/3);
        int blockY = (int)(y/3);
        return canPlaceinBox(c,board,blockX,blockY);
    }
    
    bool backtrack(vector<vector<char>>& board, int x, int y){
        
        if (x >=9) {
            return true;
        }
        int i, j ;
        for (i = x; i < 9 ; i++){
            bool found = 0;
            for (j = 0 ; j < 9; j++){  
                if (board[i][j] == '.') {
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }
        
        if (i >=9) return true;
               
        for (int num = 1; num <= 9 ; num++){
            char c = (char)(48+num);
            if (canPlace(c, board, i, j)){
                board[i][j] = c;
                bool res;
                if (j == 8) res = backtrack(board, i+1, 0);
                else res = backtrack(board,i,j+1);
                if (!res) board[i][j] = '.';
                else return true;
            }
        }
        
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0 , 0);
        return;
    }
};
