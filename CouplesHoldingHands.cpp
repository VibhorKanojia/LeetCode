//https://leetcode.com/problems/couples-holding-hands/description/
class Solution {
private:
    void swap(vector<int> & row, int i, int j){
        int temp = row[i];
        row[i]= row[j];
        row[j]= temp;
        return;
    }
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> position(n,0);
        for (int i = 0; i < n ; i++){
            position[row[i]] = i;
        }
        int count = 0;
        for (int i = 0 ; i < n; i=i+2){
            int partner = (row[i]%2 == 0)? row[i]+1: row[i]-1; 
            if (row[i+1] == partner) continue;
            else{
                count++;
                int cur_next = row[i+1];
                swap(row,i+1,position[partner]);
                position[cur_next] = position[partner];
                position[partner] = i+1;
                for (int j = 0 ; j < row.size(); j++) cout<<row[j]<<" ";
                cout<<endl;
            }
        }
        return count;
    }
};
