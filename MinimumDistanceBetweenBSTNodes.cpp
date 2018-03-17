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
    void inOrder(TreeNode * root, int & min_diff, int & pre_val, bool & flag){
        if (root == NULL) return;
        inOrder(root->left, min_diff, pre_val,flag);
        if (flag) min_diff = min(min_diff, root->val - pre_val);
        pre_val = root->val;
        flag = 1;
        inOrder(root->right,min_diff, pre_val,flag);
        return;
    }
public:
    int minDiffInBST(TreeNode* root) {
        int min_diff = INT_MAX;
        int pre_val = INT_MIN;
        bool flag = 0;
        inOrder(root, min_diff, pre_val, flag);
        return min_diff;
    }
};
