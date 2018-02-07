class Solution {
private:
    int fillPath(vector<vector<int>> & pathMatrix, vector<vector<int>> & matrix, int x, int y){
        int m = matrix.size();
        int n = matrix[x].size();
        if (pathMatrix[x][y] != 0) return pathMatrix[x][y]; 
        if (x > 0 && matrix[x][y] > matrix[x-1][y]){
            pathMatrix[x][y] = max(pathMatrix[x][y], 1+fillPath(pathMatrix,matrix,x-1,y));
        }
        if (x < m-1 && matrix[x][y] > matrix[x+1][y]){
            pathMatrix[x][y] = max(pathMatrix[x][y], 1+fillPath(pathMatrix,matrix,x+1,y));
        }
        if (y > 0 && matrix[x][y] > matrix[x][y-1]){
            pathMatrix[x][y] = max(pathMatrix[x][y], 1+fillPath(pathMatrix,matrix,x,y-1));
        }
        if (y < n-1 && matrix[x][y] > matrix[x][y+1]){
            pathMatrix[x][y] = max(pathMatrix[x][y], 1+fillPath(pathMatrix,matrix,x,y+1));
        }
        if (pathMatrix[x][y] == 0) pathMatrix[x][y] = 1;
        return pathMatrix[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> pathMatrix = matrix;
        for (int i =0 ; i < pathMatrix.size(); i++){
            for (int j = 0; j < pathMatrix[i].size(); j++){
                pathMatrix[i][j] = 0;
            }
        }
        int maxLen = 0;
        for (int i = 0 ; i < pathMatrix.size(); i++){
            for (int j = 0 ; j < pathMatrix[i].size(); j++){
                fillPath(pathMatrix,matrix, i, j);
                maxLen = max(maxLen, pathMatrix[i][j]);
            }
        }
        
        return maxLen;
    }
};
