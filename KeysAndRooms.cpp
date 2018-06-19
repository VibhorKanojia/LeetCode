class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<bool> visited(N,false);
        queue<int> keys;
        keys.push(0);
        while (!keys.empty()){
            int key = keys.front();
            keys.pop();
            visited[key] = true;
            for (int i = 0 ; i < rooms[key].size(); i++){
                if (!visited[rooms[key][i]]) keys.push(rooms[key][i]);
            }
        }
        for (int i = 0 ; i < N; i++){
            if (!visited[i]) return false;
        }
        return true;
    }
};
