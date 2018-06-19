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
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode * left = root->left;
        root->left = NULL;
        TreeNode * right = root->right;
        root->right = left;
        if (left == NULL){
            root->right = right;
            return;
        }
        else{
            while (left->right != NULL) left = left->right;
            left->right = right;
            return;
        }
    }
};
