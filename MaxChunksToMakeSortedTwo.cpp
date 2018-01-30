class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if (n == 0 || n == 1) return n;
        vector<int> leftMax(n,INT_MIN);
        vector<int> rightMin(n,INT_MAX);
        leftMax[0]=arr[0];
        rightMin[n-1] = arr[n-1];
        
        for (int i = 1 ; i < n ; i++){
            leftMax[i] = max(arr[i], leftMax[i-1]);
        }
        
        for (int i = n-2 ; i >= 0 ; i--){
            rightMin[i] = min(arr[i], rightMin[i+1]);
        }
        
        
        int chunks = 0;
        for (int i = 0 ; i < n-1; i++){
            if (leftMax[i] <= rightMin[i+1]) chunks++;
        }
        
        chunks++;
        
        return chunks;
    }
};
