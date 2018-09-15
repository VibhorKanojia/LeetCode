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
        return (root->left == NULL && root->right == NULL);
    }
    
    void pathSumHelper(TreeNode* root, int sum, int cur_sum, vector<int> path, vector<vector<int>> & result){
        if (root == NULL) return;
        
        cur_sum = cur_sum + root->val;
        path.push_back(root->val);
        
        if (cur_sum == sum && isLeaf(root)){
            result.push_back(path);
            return;
        } 
        else{
            pathSumHelper(root->left, sum, cur_sum, path, result);
            pathSumHelper(root->right, sum, cur_sum, path, result);
        }
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        pathSumHelper(root, sum, 0, path, result);
        return result;
    }
};
