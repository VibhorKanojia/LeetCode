//O(N) time O(N) space solution. O(1) space solution is too much for me.
class Solution {
private:
    void swap(vector<int> & nums, int i1, int i2){
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
        return;
    }
    
    int VI(int i, int m, int n){
        if (i < m) return 2*(m-1-i);
        else return 2*(n-1-i)+1;
    }
    
    void quickSelect(vector<int> & array, int start, int end, int K){
        int pivot = end;
        int cur_index = start;
        int n = array.size();
        for (int i = start; i < end; i++){
            if (array[i] < array[pivot]){
                swap(array, i, cur_index);
                cur_index++;
            }
        }
        swap(array, pivot, cur_index);
        if (cur_index == K) return;
        if (cur_index > K) quickSelect(array, start, cur_index-1, K);
        else quickSelect(array, cur_index+1, end, K);
        return;
    }
    
   
    
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int m = (n+1)/2;
        quickSelect(nums, 0, n-1, m);
        vector<int> nums_copy = nums;
        for (int i =0; i < n; i++){
            nums[VI(i, m, n)] = nums_copy[i];     
        }
        return;
    }
};
