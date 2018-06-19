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
    
    void swap(TreeNode * a, TreeNode * b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
    
    void inorder(TreeNode * root,TreeNode *& pre, vector<TreeNode *> & buffer){
        if (root == NULL) return;
        inorder(root->left, pre,buffer);
        if (pre != NULL){
            if (root->val < pre->val){
                buffer.push_back(pre);
                buffer.push_back(root);
            }
        }
        pre = root;
        inorder(root->right,pre,buffer);
        return;
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> buffer;
        TreeNode * pre = NULL;
        inorder(root,pre,buffer);
        if (buffer.size() == 2){
            swap(buffer[0], buffer[1]);
        }
        else if (buffer.size() == 4){
            swap(buffer[0], buffer[3]);
        }
        return;
    }
};
