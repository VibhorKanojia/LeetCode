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
    int findMax(vector<int> nums, int start, int end){
        int max_val = INT_MIN;
        int max_index = -1;
        for (int i = start; i <end; i++){
            if (nums[i] > max_val){
                max_val = nums[i];
                max_index= i;
            }
        }
        return max_index;
    }
    
    TreeNode * constructTree(vector<int> & nums, int start, int end){
        if (start >= end) return NULL;
        int index = findMax(nums,start,end);
        TreeNode * root = new TreeNode(nums[index]);
        root->left = constructTree(nums,start,index);
        root->right = constructTree(nums,index+1,end);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode * root = NULL;
        root = constructTree(nums,0,nums.size());
        return root;
    }
};
