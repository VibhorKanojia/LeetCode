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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        int count =1;
        int a1 = minDepth(root->left);
        int a2 = minDepth(root->right);
        if (a1 == 0){
            count = count + a2;
        }
        if (a2 == 0){
            count = count + a1;
        }
        if (a1 !=0 && a2!=0 ){
            count = count + min (a1,a2);
        }
        return count;
    }
};
