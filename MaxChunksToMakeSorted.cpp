class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int len = arr.size();
        if (len == 0 || len == 1) return len;
        int chunks = 0;
        int i = len -1;
        int pos = arr[i];
        while (i >= pos){
            if (i == pos) chunks++;
            i--;
            pos = min(pos, arr[i]);        
        }
        return chunks;
    }
};
