//BEATS 100%
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    UndirectedGraphNode * cloneGraphHelper(UndirectedGraphNode * node, unordered_map<int, UndirectedGraphNode *> & mapper){
        UndirectedGraphNode * root = new UndirectedGraphNode(node->label);
        mapper[root->label] = root;
        for (int i =0; i < (node->neighbors).size(); i++){
            int next_label = (node->neighbors)[i]->label;
            if (mapper.find(next_label) != mapper.end()){
                (root->neighbors).push_back(mapper[next_label]);
            }
            else{
                (root->neighbors).push_back(cloneGraphHelper(node->neighbors[i], mapper));
            }
        }
        return root;
    }
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<int, UndirectedGraphNode *> mapper;
        return cloneGraphHelper(node, mapper);
    }
};
