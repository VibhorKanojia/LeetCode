class Solution {
    
private:
    int root(vector<int> & dsu, int A){
        while (dsu[A] != A){
            dsu[A] = dsu[dsu[A]];
            A = dsu[A];
        }
        return A;
    }
    
    bool addEdge(vector<int> & dsu, vector<int> &size, vector<int> edge){
        int rootA = root(dsu, edge[0]);
        int rootB = root(dsu, edge[1]);
        if (rootA == rootB) return false;
        if (size[rootA] <= size[rootB]){
            dsu[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else{
            dsu[rootB] = rootA;
            size[rootA] += size[rootB];
        }
        return true;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size()+1;
        vector<int> dsu(N,-1);
        vector<int> size(N,1);
        for (int i = 0; i < N ; i++) dsu[i] = i;
        for (int i =0 ; i < edges.size(); i++){
            if (!addEdge(dsu,size,edges[i])) return edges[i];
        }
        vector<int> temp;
        return temp;
    }
};
