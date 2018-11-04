class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int ** fareArray = new int *[n];
        vector<int> distArray(n, INT_MAX);
        for (int i =0; i < n; i++){
            fareArray[i] = new int[n];
        }
        
        for (int i = 0; i < n ; i++){
            for (int j = 0; j < n ; j++){
                fareArray[i][j] = -1;
            }
        }
        
        distArray[src] = 0;
        
        for (int i = 0 ; i < flights.size(); i++){
            fareArray[flights[0]][flights[1]] = flights[2];
        }
        
        queue<int> buffer;
        buffer.push(str);
        int level_count = 0;
        while (K >= 0 && !buffer.empty()){
            int cur_node = buffer.front();
            buffer.pop();
            level_count--;
            
            for (int j =0 ; j < n; j++){
                if (fareArray[cur_node][j] != -1){
                    distArray[j] = min(distArray[j], distArray[cur_node] + fareArray[cur_node][j]);   
                }
            }
            if (level_count == 0){
                K--;
                level_count = buffer.size();
            }
        }
        return distArray[dst];
    }
};
