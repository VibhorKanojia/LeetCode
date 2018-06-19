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
        else return false;
    }
    
    int maxHelper(TreeNode * root, int & absMax){
        if (root == NULL) return 0;
        int maxSum = INT_MIN;
        if (isLeaf(root)) {
            absMax = max(absMax, root->val);
            return root->val;
        }
        int lmax = max(0, maxHelper(root->left,absMax));
        int rmax = max(0, maxHelper(root->right,absMax));
        
        absMax = max(absMax, lmax+rmax+root->val);
        return root->val + max(lmax, rmax);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int absMax = INT_MIN;
        maxHelper(root,absMax);
        return absMax;
    }
};
