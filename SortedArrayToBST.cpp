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
    TreeNode * makeTree(vector<int> & nums, int begin, int end, TreeNode * root){
        if (end - begin < 1){
            return NULL;
        }
        int mid = begin + (end-begin)/2;
        root = new TreeNode (nums[mid]);
        root->left = makeTree(nums,begin, mid, root->left);
        root->right = makeTree(nums,mid+1, end, root->right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = NULL;
        if (nums.size() == 0) return root;
        root = makeTree(nums, 0, nums.size(), root);
        return root;
    }
};
