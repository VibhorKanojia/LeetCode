struct data{
    int val;
    int row;
    int col;
    data(int val, int row, int col){
        this->val = val;
        this->row = row;
        this->col = col;
    }
};

class Compare{
    public:
        bool operator()(data * a, data * b){
            return a->val > b->val;
        }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<data *, vector<data *>, Compare> heap;
        for (int i = 0 ; i < n ; i++){
            data * temp = new data(matrix[0][i], 0, i);
            heap.push(temp);
        }
        k--;
        while(k--){
            data * temp = heap.top();
            heap.pop();
            if (temp->row != n-1){
                heap.push(new data(matrix[temp->row+1][temp->col], temp->row+1, temp->col));
            }
        }
        return heap.top()->val;
    }
};
