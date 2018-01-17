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
    void inOrderTraversal(TreeNode * root, vector<int> & inOrder){
        if (root == NULL) return;
        inOrderTraversal(root->left, inOrder);
        inOrder.push_back(root->val);
        inOrderTraversal(root->right, inOrder);
        return;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        vector<int> inOrder;
        inOrderTraversal(root, inOrder);
        for (int i = 0 ; i < inOrder.size()-1; i++){
            if (inOrder[i] >= inOrder[i+1]) return false;
        }
        return true;
    }
};
