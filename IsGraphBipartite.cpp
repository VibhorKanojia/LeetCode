class Solution {
private: 
    bool bfs(vector<int> & color_map, vector<vector<int>> & graph, int index){
            queue<int> buffer;
            buffer.push(index);
            color_map[index] = 0;
            while(!buffer.empty()){
                int cur_node = buffer.front();
                buffer.pop();
                int cur_color = color_map[cur_node];
                int next_color = (cur_color+1)%2;
                for (int i = 0; i < graph[cur_node].size(); i++){
                    int next_node = graph[cur_node][i];
                    if (color_map[next_node] == -1){
                        color_map[next_node] = next_color;
                        buffer.push(next_node);
                    }
                    else if (color_map[next_node] != next_color) return false;    
                }
            }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color_map(n, -1);        
        
        for (int i =0; i < n; i++){
            if (color_map[i] != -1) continue;
            if (!bfs(color_map, graph, i)) return false;
        }
        return true;
    }
};
