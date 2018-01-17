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
    int findTiltHelper(TreeNode * root, int & tiltSum){
        if (root == NULL) return 0;
        int sum = 0;
        int lsum = findTiltHelper(root->left,tiltSum);
        int rsum = findTiltHelper(root->right,tiltSum);
        sum = root->val + lsum + rsum;
        tiltSum += abs(lsum - rsum);
        return sum;
    }
    
public:
    int findTilt(TreeNode* root) {       
        int tiltSum = 0;
        findTiltHelper(root, tiltSum);
        return tiltSum;
    }
};
