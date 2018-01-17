class Solution {
private:
    void fillGrid(vector<vector<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[i].size();
        grid[i][j] = 'X';
        if (i > 0 && grid[i-1][j] == '1') fillGrid(grid, i-1, j);
        if (i < n-1 && grid[i+1][j] == '1') fillGrid(grid, i+1, j);
        if (j > 0 && grid[i][j-1] == '1') fillGrid(grid, i, j-1);
        if (j < m-1 && grid[i][j+1] == '1') fillGrid(grid, i, j+1);
        return;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0 ; i < grid.size(); i++){
            for (int j = 0 ; j < grid[i].size(); j++){
                if (grid[i][j] == '1') {
                    fillGrid(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
