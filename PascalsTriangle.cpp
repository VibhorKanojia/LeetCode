class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0 ; i < numRows ; i++){
            if (i == 0){
                vector<int> temp;
                temp.push_back(1);
                triangle.push_back(temp);
            }
            else if (i == 1){
                vector<int> temp;
                temp.push_back(1);
                temp.push_back(1);
                triangle.push_back(temp);
            }
            else{
                vector<int> temp;
                temp.push_back(1);
                for (int j = 1; j < i ; j++){
                    temp.push_back(triangle[i-1][j-1] + triangle[i-1][j]);
                }
                temp.push_back(1);
                triangle.push_back(temp);
            }
        }
        return triangle;
    }
};
