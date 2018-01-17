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
    bool isLeaf(TreeNode * node){
        if (node->left == NULL) return (node->right == NULL);    
        return false;
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (isLeaf(root) && sum == root->val) return true;
        else return (hasPathSum(root->right, sum - root->val) || hasPathSum(root->left, sum- root->val));
    }
};
