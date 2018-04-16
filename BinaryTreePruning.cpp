/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isLeaf(TreeNode * root){
        if (root->left == NULL) return root->right == NULL;
        return false;
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) return NULL;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && isLeaf(root)) return NULL;
        return root;
    }
};
