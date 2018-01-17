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
    int pathLength(TreeNode * root){
        if (root == NULL) return 0;
        else return (1 + max(pathLength(root->right),pathLength(root->left)));
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        return max(pathLength(root->right) + pathLength(root->left), max(diameterOfBinaryTree(root->right), diameterOfBinaryTree(root->left)));
    }
};
