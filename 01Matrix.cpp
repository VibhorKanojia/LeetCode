struct cell{
    int x;
    int y;
    cell(int x, int y){
        this->x = x;
        this->y = y;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> result = matrix;
        queue<cell *> buffer;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i=0; i < n; i++){
            for (int j = 0 ; j < m; j++){
                if (matrix[i][j] == 0){
                    cell * temp = new cell(i,j);
                    buffer.push(temp);
                    result[i][j] = 0;
                }
                else{
                    result[i][j] = -1;
                }
            }
        }
        while (!buffer.empty()){
            cell * cur_cell = buffer.front();
            buffer.pop();
            int x = cur_cell->x;
            int y = cur_cell->y;
            if (x > 0 && result[x-1][y] == -1){
                result[x-1][y] = result[x][y]+1;
                cell * temp = new cell(x-1, y);
                buffer.push(temp);
            }
            if (y > 0 && result[x][y-1] == -1){
                result[x][y-1] = result[x][y]+1;
                cell * temp = new cell(x, y-1);
                buffer.push(temp);
            }
            if (x < n-1 && result[x+1][y] == -1){
                result[x+1][y] = result[x][y]+1;
                cell * temp = new cell(x+1, y);
                buffer.push(temp);
            }
            if (y < m-1 && result[x][y+1] == -1){
                result[x][y+1] = result[x][y]+1;
                cell * temp = new cell(x, y+1);
                buffer.push(temp);
            }
        }
        
        return result;
    }
};
