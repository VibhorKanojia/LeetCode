//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
    int find(vector<int> & array, int start, int end, int val){
        for (int i = start ; i < end; i++){
            if (array[i] == val) return i;
        }
        return -1;
    }
    
    TreeNode * buildTreeHelper(vector<int> & postorder, vector<int> & inorder, int start, int end){
        if (start >= end) return NULL;
        int val = postorder[postorder.size()-1];
        int index = find(inorder, start, end, val); // O(N) in the worst case;
        if (index == -1) return NULL;
        TreeNode * root = new TreeNode(val);
        postorder.pop_back();
        root->right = buildTreeHelper(postorder,inorder,index+1,end);
        root->left = buildTreeHelper(postorder,inorder,start,index); //THIS ORDERING IS IMPORTANT 
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) return NULL;
        TreeNode * root = buildTreeHelper(postorder,inorder,0,n);
        return root;  
    }
};
