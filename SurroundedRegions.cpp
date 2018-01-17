class Solution {
private:
    void solveHelper(vector<vector<char>>& board, int i, int j){
        int n = board.size();
        if (i < 0 || i >= n) return;
        int m = board[i].size();
        if (j < 0 || j >= m) return;
        
        if (board[i][j] != 'O') return;
        
        board[i][j] = 'N';
        solveHelper(board,i-1,j);
        solveHelper(board,i,j+1);
        solveHelper(board,i+1,j);
        solveHelper(board,i,j-1);
        return;
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        for (int i =0 ; i < n ; i++){
            solveHelper(board,i,0);
            solveHelper(board,i,m-1);
        }
        
        for (int j =0 ; j < m ; j++){
            solveHelper(board,0,j);
            solveHelper(board,n-1,j);
        }
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (board[i][j] == 'N') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
        return;
    }
};
