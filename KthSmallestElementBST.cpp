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
    void inOrder(TreeNode * root, vector<int> & array, int k){
        if (root == NULL) return;
        inOrder(root->left,array, k);
        array.push_back(root->val);
        if (array.size() == k) return;
        inOrder(root->right,array,k);
        return;
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
         vector<int> array;
         inOrder(root, array,k);
         return array[k-1];
    }
};
