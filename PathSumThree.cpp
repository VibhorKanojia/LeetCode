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
    
    int pathSumHelper(TreeNode * root, int sum){
        if (root == NULL) return 0;
        int answer = 0;
        if (sum == root->val) {
            answer++;
        }
        answer += pathSumHelper(root->left, sum - root->val);
        answer += pathSumHelper(root->right, sum - root->val);
        return answer;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return pathSumHelper(root, sum) + pathSum(root->left, sum)+pathSum(root->right,sum);
    }
};
