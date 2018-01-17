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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode * l = root;
        TreeNode * r = root;
        int lh = 0;
        int rh = 0;
        while (l!= NULL){
            l = l->left;
            lh++;
        }
        
        while (r!= NULL){
            r = r->right;
            rh++;
        }
        if (lh == rh) return (pow(2, lh) -1);
        else return 1+countNodes(root->left) + countNodes(root->right);
        
    }
};
