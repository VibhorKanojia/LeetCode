/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    stack<int> values;
    
     void fillStack(TreeNode *root, int val){
        if (root->left != NULL){
            int newval = val*10+(root->left)->val;
            fillStack(root->left, newval);
        }
        if (root->right != NULL){
            int newval = val*10+(root->right)->val;
            fillStack(root->right, newval);
        }
        if (root->left == NULL && root->right == NULL){
            values.push(val);
        }
    }
    
    
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        fillStack(root,root->val);
        int sum =0;
        while(!values.empty()){
            sum = sum + values.top();
            values.pop();
        }
        return sum;
    }
   
};
