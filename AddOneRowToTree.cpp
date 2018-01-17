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
    TreeNode * addOneRowHelper(TreeNode * root, int v, int d, string pos){
        if (root == NULL){
            if (d == 1){
                TreeNode * new_root = new TreeNode(v);
                return new_root;
            }
            else return NULL;
        }
        else if (d == 1){
            TreeNode * new_root = new TreeNode(v);
            if (pos == "left"){
                new_root->left = root;
            }
            else{
                new_root->right = root;
            }
            return new_root;
        }
        else{
            root->left = addOneRowHelper(root->left,v,d-1,"left");
            root->right = addOneRowHelper(root->right,v,d-1,"right");
            return root;
        }
        
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode * new_root = addOneRowHelper(root, v, d,"left");
        return new_root;
    }
};
