class Solution {
private:
    int root(vector<int> & dsu, int A){
        if (dsu[A] != A) dsu[A] = root(dsu, dsu[A]);
        return dsu[A];
    }
    
    bool addEdge(vector<int>& dsu, vector<int> & rank, vector<int> edges){
        int rootA = root(dsu, edges[0]);
        int rootB = root(dsu, edges[1]);
        if (rootA == rootB) return false;
        if (rank[rootA] < rank[rootB]){
            dsu[rootA] = rootB;
        }
        else if (rank[rootB] < rank[rootA]){
            dsu[rootB] = rootA;
        }
        else{
            dsu[rootA] = rootB;
            rank[rootB]++;
        }
        return true;
    }
    
    vector<int> makePair(int u, int v){
        vector<int> result;
        result.push_back(u);
        result.push_back(v);
        return result;
    }
    
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size() +1;
        vector<int> dsu(N,-1);
        vector<int> rank(N,0);
        vector<int> par(N,-1);
        vector<int> cand1;
        int index_of_cand2 = -1;
        for (int i = 0 ; i < edges.size(); i++){
            if (par[edges[i][1]] == -1) par[edges[i][1]] = edges[i][0];
            else{
                cand1 = makePair(par[edges[i][1]], edges[i][1]);
                index_of_cand2 = i;
                break;
            }
        }
        
        for (int i =0 ; i < N; i++) dsu[i] = i;
        
        for (int i =0 ; i < edges.size(); i++){
            if (i == index_of_cand2) continue;
             
            if (!addEdge(dsu, rank, edges[i])) {
                 if (index_of_cand2 == -1) return edges[i];
                 else return cand1;
            }
        }
        return edges[index_of_cand2];
    }
};
