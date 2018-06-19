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
    TreeNode * findMax(TreeNode * root){
        while (root->right) root = root->right;
        return root;
    }
    void swap(TreeNode * a, TreeNode * b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
    
    TreeNode * deleteRoot(TreeNode * root){
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        TreeNode * maxNode = findMax(root->left);
        swap(root,maxNode);
        deleteRoot(maxNode);
        return root;
    }
    
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL) return NULL;
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        if (root->val < L || root->val > R) root = deleteRoot(root); 
        return root;
    }
};
