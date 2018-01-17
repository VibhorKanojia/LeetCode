/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Elem{
    int level;
    TreeNode * node;
    Elem(TreeNode * node,int level){
        this->node = node;
        this->level = level;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<Elem *> buffer;
        int depth = 1;
        Elem * temp = new Elem(root,1);
        buffer.push(temp);
        while (!buffer.empty()){
            Elem * cur_elem = buffer.front();
            depth = max(depth, cur_elem->level);
            buffer.pop();
            if (cur_elem->node->left != NULL) {
                Elem * e = new Elem(cur_elem->node->left, cur_elem->level+1);
                buffer.push(e);
                
            }
            if (cur_elem->node->right != NULL) {
                Elem * e = new Elem(cur_elem->node->right, cur_elem->level+1);
                buffer.push(e);
            }
        }
        return depth;
    }
};
