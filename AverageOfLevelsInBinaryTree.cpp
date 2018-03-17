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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> average;
        if (root == NULL) return average;
        queue<TreeNode *> buffer;
        buffer.push(root);
        int count = 1;
        double sum = 0;
        int level_count = 0;
        while (!buffer.empty()){
            TreeNode * node = buffer.front();
            buffer.pop();
            sum += node->val;
            count--;
            level_count++;
            if (node->left != NULL){
                buffer.push(node->left);
            }
            if (node->right != NULL){
                buffer.push(node->right);
            }
            if (count == 0){
                average.push_back(sum/level_count);
                sum = 0;
                level_count = 0;
                count = buffer.size();
            }
        }
        return average;
    }
};
