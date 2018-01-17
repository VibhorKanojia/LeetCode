/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node{
    TreeNode * node;
    int level;
    Node(TreeNode * node,int level){
        this->node = node;
        this->level = level;
    }
};
class Solution {

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;
        queue<Node *> buffer;
        if (root == NULL) return answer;
        
        struct Node * root_node = new Node(root,0);
        buffer.push(root_node);
        while(!buffer.empty()){
            Node * cur_node = buffer.front();
            buffer.pop();
            if (answer.size() <= cur_node->level){
                vector<int> temp;
                temp.push_back((cur_node->node)->val);
                answer.push_back(temp);
            }
            else{
                (answer[cur_node->level]).push_back((cur_node->node)->val);
            }
            if ((cur_node->node)->left != NULL){
              struct Node * temp_node = new Node((cur_node->node)->left, cur_node->level+1);
              buffer.push(temp_node);
            }
            if ((cur_node->node)->right != NULL){
              struct Node * temp_node = new Node((cur_node->node)->right, cur_node->level+1);
              buffer.push(temp_node);
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
