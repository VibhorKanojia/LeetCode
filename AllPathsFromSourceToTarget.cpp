//SIMPLE BACKTRACKING
class Solution {
private:
    void findPath(vector<vector<int>> & graph, int s, int e, vector<int> path, vector<vector<int>> & result){
        if (s == e){
            result.push_back(path);
            return;
        }
        for (int i = 0; i < graph[s].size(); i++){
            path.push_back(graph[s][i]);
            findPath(graph,graph[s][i], e, path, result);
            path.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        int start = 0;
        int end = graph.size()-1;
        path.push_back(start);
        findPath(graph, start, end, path, result);
        return result;
    }
};
