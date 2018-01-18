struct Node{
    int id;
    unordered_set<Node *> adjList;
    Node(int id){
        this->id = id;
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<Node *> tree;
        vector<int> roots;
        if (n == 1){
            roots.push_back(0);
            return roots;
        }
        
        for (int i = 0 ; i < n ; i++){
            Node * temp = new Node(i);
            tree.push_back(temp);
        }
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;
            (tree[u]->adjList).insert(tree[v]);
            (tree[v]->adjList).insert(tree[u]);
        }
        
        queue<Node *> leafBuffer;
        for (int i = 0 ; i < n ; i++){
            if ((tree[i]->adjList).size() == 1) {
                leafBuffer.push(tree[i]);
            }
        }
        
        while (n > 2){
            int leafCount = leafBuffer.size();
            while (leafCount--){
                Node * cur_leaf = leafBuffer.front();
                leafBuffer.pop();
                n--;
                for (auto it = (cur_leaf->adjList).begin() ; it != (cur_leaf->adjList).end(); it++){
                    Node * neighbor = *it;
                    (neighbor->adjList).erase(cur_leaf);
                    if ((neighbor->adjList).size() == 1) {
                        leafBuffer.push(neighbor);
                    }
                }
            }
        }
        
        while (!leafBuffer.empty()){
            roots.push_back(leafBuffer.front()->id);
            leafBuffer.pop();
        }
        
        return roots;
    }
};
