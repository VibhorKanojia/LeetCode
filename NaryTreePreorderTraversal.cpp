/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<Node *> buffer;
        buffer.push(root);
        while (!buffer.empty()){
            Node * first = buffer.top();
            buffer.pop();
            result.push_back(first->val);
            for (int i =(first->children).size()-1 ; i >=0 ; i--){
                buffer.push((first->children)[i]);
            }
        }
        return result;
    }
};
