class NumMatrix {
private:
    vector<vector<int>> cumMatrix;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int n = matrix.size();
        for (int i = 0 ; i <n; i++){
            int m = matrix[i].size();
            vector<int> temp(m,0);
            cumMatrix.push_back(temp);
            for (int j = 0; j < m ; j++){
                if (i == 0 && j == 0){
                    cumMatrix[i][j] = matrix[i][j];
                }
                else if (i == 0){
                    cumMatrix[i][j] = cumMatrix[i][j-1]+matrix[i][j];
                }
                else if (j == 0){
                    cumMatrix[i][j] = cumMatrix[i-1][j] +matrix[i][j];
                }
                else{
                    cumMatrix[i][j] = cumMatrix[i-1][j] + cumMatrix[i][j-1] + matrix[i][j] - cumMatrix[i-1][j-1]; 
                }
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int answer = cumMatrix[row2][col2];
        if (row1 > 0){
            answer -= cumMatrix[row1-1][col2];
        }
        if (col1 > 0){
            answer -= cumMatrix[row2][col1-1];
        }
        if (row1 > 0 && col1 > 0){
            answer += cumMatrix[row1-1][col1-1];
        }
        return answer;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
