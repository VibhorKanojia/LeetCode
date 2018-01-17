class Solution {
public:
    void swapFunction(vector<unordered_map<int,int>::iterator> & heap, int index1, int index2){
        unordered_map<int,int>::iterator temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
        return;
    }
    
    void shiftUp(int index, vector<unordered_map<int,int>::iterator> & heap){
        if (index <= 0) return;
        int parIndex = floor((index-1)/2);
        if (heap[index]->second > heap[parIndex]->second){
            swapFunction(heap,index,parIndex);
            shiftUp(parIndex, heap);
        }
    }
    
    void shiftDown(int index, vector<unordered_map<int,int>::iterator> & heap){
        int child1 = 2*index+1;
        int child2 = 2*index+2;
        int childIndex;
        int size = heap.size();
        if (child1 < size && child2 < size){
            childIndex = (heap[child1]->second > heap[child2]->second)?child1:child2;
        }
        else if (child1 < size){
            childIndex = child1;
        }
        else{
            return;
        }
        if (heap[index]->second < heap[childIndex]->second){
            swapFunction(heap,index,childIndex);
            shiftDown(childIndex, heap);
        }
        return;
    }
    
    int getMax(vector<unordered_map<int,int>::iterator> & heap){
        int maxElem = heap[0]->first;
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        shiftDown(0,heap);
        return maxElem;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter;
        int size = nums.size();
        for (int i = 0 ; i < size ; i++){
            if (counter.find(nums[i]) == counter.end()){
                counter[nums[i]] = 1;
            }
            else{
                counter[nums[i]] +=1;
            }
        }
        
        int heapSize = counter.size();
        vector<unordered_map<int,int>::iterator> heap;
        
        unordered_map<int,int>::iterator it;
        for (it = counter.begin() ; it != counter.end()  ; it++){
            heap.push_back(it);
            shiftUp(heap.size()-1, heap);
        }
        
        vector<int> answer;
        for (int i = 0 ; i < k ; i++){
            answer.push_back(getMax(heap));
        }
        
        return answer;
           
    }
};
