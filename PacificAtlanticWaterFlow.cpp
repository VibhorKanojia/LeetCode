struct cell{
    int x;
    int y;
    cell(int x,int y){
        this->x = x;
        this->y = y;
    }
};

class Solution {
private:
    void bfs(vector<vector<int>>& matrix, vector<vector<bool>> & visited, queue<cell *> & buffer){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> direction;
        direction.push_back(pair<int,int>(1,0));
        direction.push_back(pair<int,int>(-1,0));
        direction.push_back(pair<int,int>(0,1));
        direction.push_back(pair<int,int>(0,-1));
        while(!buffer.empty()){
            cell * cur = buffer.front();
            buffer.pop();
            visited[cur->x][cur->y] = 1;
            for (int i = 0 ; i < direction.size(); i++){
                int x = cur->x + direction[i].first;
                int y = cur->y + direction[i].second;
                if (x < 0 || x >= m || y <0 || y >=n || visited[x][y]) continue;
                if (matrix[x][y] >= matrix[cur->x][cur->y]) buffer.push(new cell(x,y));
            }
        }
        return;
    }
    
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> result;
        int m = matrix.size();
        if (m == 0) return result;
        int n = matrix[0].size();
        vector<vector<bool>> pacific;
        vector<vector<bool>> atlantic;
        
        queue<cell *> pq;
        queue<cell *> aq;
        for (int i =0 ; i < m ; i++){
            vector<bool> temp(n,0);
            pacific.push_back(temp);
            atlantic.push_back(temp);
        }
        for (int i = 0 ; i < m ; i++){
            pq.push(new cell(i,0));
            aq.push(new cell(i,n-1));
        }
        
        for (int j = 0 ; j < n ; j++){
            pq.push(new cell(0,j));
            aq.push(new cell(m-1,j));
        }
        
        bfs(matrix, pacific, pq);
        bfs(matrix, atlantic, aq);
        for (int i =0 ; i < m ; i++){
            for (int j = 0; j < n ; j++){
                if (pacific[i][j] && atlantic[i][j]) result.push_back(pair<int,int>(i,j));
            }
        }
        
        return result;
    }
};
