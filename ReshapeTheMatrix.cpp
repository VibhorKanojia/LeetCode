class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> matrix;
        if (nums.size() == 0) return matrix;
        if (nums.size()*nums[0].size() != r*c) return nums;
        
        for (int i = 0 ; i < r; i++){
            vector<int> row;
            for (int j = 0 ; j < c; j++){
                row.push_back(0);
            }
            matrix.push_back(row);
        }
        
        int new_i = 0;
        int new_j = 0;
        
        for (int i = 0 ; i < nums.size(); i++){
            for (int j = 0 ; j < nums[i].size(); j++){
                matrix[new_i][new_j] = nums[i][j];
                new_j++;
                if (new_j == c){
                    new_j = 0;
                    new_i++;
                }
            }
        }
        
        return matrix;
    }
    
};
