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
    void preOrder(TreeNode * root,vector<int> & preOrderLeft){
        if (root == NULL) {
            preOrderLeft.push_back(INT_MAX);
            return;
        }
        preOrderLeft.push_back(root->val);
        preOrder(root->left,preOrderLeft);
        preOrder(root->right,preOrderLeft);
        return;
    }
    
    void preOrderMirror(TreeNode * root,vector<int> & preOrderRight){
        if (root == NULL) {
            preOrderRight.push_back(INT_MAX);
            return;
        }
        preOrderRight.push_back(root->val);
        preOrderMirror(root->right,preOrderRight);
        preOrderMirror(root->left,preOrderRight);
        return;
    }
    
    
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        vector<int> preOrderLeft;
        vector<int> preOrderRight;
        preOrder(root->left, preOrderLeft);
        preOrderMirror(root->right, preOrderRight);
        return (preOrderLeft == preOrderRight);
    }
};
