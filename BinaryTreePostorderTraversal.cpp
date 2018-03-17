//ITERATIVE APPROACH
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) return postorder;
        stack<TreeNode *> buffer;
        buffer.push(root);
        while(!buffer.empty()){
            TreeNode * cur_node = buffer.top();
            buffer.pop();
            postorder.push_back(cur_node->val);
            if (cur_node->left != NULL) buffer.push(cur_node->left);   
            if (cur_node->right != NULL) buffer.push(cur_node->right);
            
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;   
    }
};
