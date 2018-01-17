class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int i = 0 ; i <= rowIndex ; i++){
            if (i == 0){
                row.push_back(1); 
            }
            else if (i == 1){
                row.push_back(1);
            }
            else{
                for (int j = i-1; j >= 1 ; j--){
                    row[j] = (row[j-1] + row[j]);
                }
                row.push_back(1);
            }
        }
        return row;
    }
};
