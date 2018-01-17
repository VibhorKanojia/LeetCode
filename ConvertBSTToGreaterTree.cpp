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
    void inorder(TreeNode * root, int& sum){
        if (root == NULL) return;
        inorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        inorder(root->left,sum);
        return;
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) return NULL;
        int sum = 0;
        inorder(root, sum);
        return root;
    }
};
