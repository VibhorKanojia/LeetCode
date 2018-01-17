class Solution {
private:
    bool canPlaceinBox(char c, vector<vector<char>>&board, int bx,int by, int x, int y){
        for (int i = bx*3; i < bx*3+3; i++){
            for (int j = by*3; j < by*3+3; j++){
                if (board[i][j] == c && i != x && j != y) return false;
            }
        }
        return true;
    }
    
    bool canPlace(char c, vector<vector<char>>&board, int x, int y){
        for (int i = 0 ; i < 9 ; i++){
            if (board[i][y] == c && i != x) return false;
            if (board[x][i] == c && i != y) return false;
        }    
        int blockX = (int)(x/3);
        int blockY = (int)(y/3);
        return canPlaceinBox(c,board,blockX,blockY, x, y);
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0 ; i < 9; i++){
            for (int j = 0 ; j < 9; j++){
                if (board[i][j] == '.') continue;
                else{
                    char c = board[i][j];
                    if (!canPlace(c,board,i,j))return false;
                }
            }
        }
        
        return true;
    }
};
