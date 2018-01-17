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
        return (root->left == NULL && root->right == NULL);
    }
    
    int helperFunction(TreeNode *root, bool isLeft){
        if (root == NULL) return 0;
        if (isLeaf(root) && isLeft) return root->val;
        if (isLeaf(root)) return 0;
        
        return helperFunction(root->left,1) + helperFunction(root->right,0);
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helperFunction(root,0);
    }
};
