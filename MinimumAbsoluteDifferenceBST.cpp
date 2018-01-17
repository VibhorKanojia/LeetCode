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

    void inorderTraversal(TreeNode * root, vector<int> & inorderTree){
        if (root == NULL) return;
        inorderTraversal(root->left, inorderTree);
        inorderTree.push_back(root->val);
        inorderTraversal(root->right, inorderTree);
        return;
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorderTree;
        inorderTraversal(root, inorderTree);
        int minElem = INT_MAX;
        int size = inorderTree.size();
        for (int i = 0 ; i < size -1 ; i++){
            if (inorderTree[i+1] - inorderTree[i] < minElem) minElem = inorderTree[i+1] - inorderTree[i];
        }
        return minElem;
    }
    
    
};
