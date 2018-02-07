struct data{
    int val1;
    int val2;
    int index; //Index of the element in nums2
    data(int v1, int v2, int ind){
        this->val1 = v1;
        this->val2 = v2;
        this->index = ind;
    }
};

class Compare{
    public:
        bool operator()(data * a, data * b){
            return (a->val1 + a->val2 > b->val1 + b->val2);
        }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        int n = nums1.size();
        int m = nums2.size();
        k = min(k,m*n);
        if (k == 0 || n == 0 || m == 0) return result;
        priority_queue<data *, vector<data *>, Compare> heap;
        
        int count = 0;
        int index  = 0;
        while (count < k && index < nums1.size()){
            data * d = new data(nums1[index], nums2[0], 0);
            heap.push(d);
            count++;
            index++;
        }
        
        count  = 0;
        while (count < k){
            data * temp = heap.top();
            heap.pop();
            result.push_back(pair<int,int>(temp->val1, temp->val2));
            count++;
            if (temp->index < m-1){
                heap.push(new data(temp->val1, nums2[temp->index+1],temp->index+1));
            }
        }
        return result;
    }
};
