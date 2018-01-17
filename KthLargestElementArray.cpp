class Solution {
public:
    void swapFunction(vector<int> & heap, int index, int parIndex){
        heap[index] = heap[index] + heap[parIndex];
        heap[parIndex] = heap[index] - heap[parIndex];
        heap[index] = heap[index] - heap[parIndex];
        return;
    }
    
    void shiftUp(int index, vector<int> & heap){
        if (index <= 0) return;
        int parIndex = floor((index-1)/2);
        if (heap[index] > heap[parIndex]){
            swapFunction(heap,index,parIndex);
            shiftUp(parIndex,heap);
        }
        return;
    }
    
    void shiftDown(int index, vector<int> & heap){
        int child1 = 2*index+1;
        int child2 = 2*index+2;
        int size = heap.size();
        int childIndex;
        if (child1 < size && child2 < size){
            childIndex = (heap[child1]> heap[child2])?child1:child2;
        }
        else if (child1 < size){
            childIndex = child1;
        }
        else{
            return;
        }
        if (heap[index] < heap[childIndex]){
            swapFunction(heap,index,childIndex);
            shiftDown(childIndex, heap);
        }
        return;
    }
    
    int getMax(vector<int> & heap){
        int maxElem = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        shiftDown(0,heap);
        return maxElem;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> heap;
        for (int i = 0 ; i < size ; i++){
            heap.push_back(nums[i]);
            shiftUp(i, heap);
        }
        int kthLargestElem;
        for (int i = 0 ; i < k ; i++){
            kthLargestElem = getMax(heap);
        }
        return kthLargestElem;
    }
};
