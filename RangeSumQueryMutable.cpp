//https://leetcode.com/problems/range-sum-query-mutable/description/
class NumArray {
private:
    vector<int> segmentTree;
    int elemcount;
    
    void updateHelper(int node, int start, int end, int idx, int val){
        if (start == end){
            segmentTree[node] = val;
        }
        else{
            int mid = (start+end)/2;
            if (start <= idx && idx <= mid){
                updateHelper(2*node+1, start, mid, idx, val);
            }
            else{
                updateHelper(2*node+2,mid+1, end, idx, val);
            }
            segmentTree[node] = segmentTree[2*node+1] + segmentTree[2*node+2];
        }
        return;
    }

    int queryHelper(int node, int start, int end, int i, int j){
        if (start > j || end < i) return 0;
        if (start >= i && end <=j) return segmentTree[node];
        else{
            int mid = (start+end)/2;
            int v1 = queryHelper(2*node+1, start, mid, i, j);
            int v2 = queryHelper(2*node+2, mid+1, end, i, j);
            return v1+v2;
        }
    }
    
    void buildTree(vector<int> & nums, int node, int start, int end){
        if (start == end) segmentTree[node] = nums[start];
        else{
            int mid = (start+end)/2;
            buildTree(nums, 2*node+1, start, mid);
            buildTree(nums, 2*node+2, mid+1, end);
            segmentTree[node] = segmentTree[2*node+1]+segmentTree[2*node+2];
        }
        return;
    }

public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return;
        int m = 2*n-1;
        for (int i = 0 ; i < m; i++) segmentTree.push_back(0);
        elemcount = n;
        buildTree(nums, 0, 0, n-1);
        
    }
    
    void update(int i, int val) {
        updateHelper(0,0,elemcount-1,i,val);
    }
    
    int sumRange(int i, int j) {
        return queryHelper(0,0,elemcount-1,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
