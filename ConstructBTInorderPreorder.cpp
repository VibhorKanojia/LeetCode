//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
    
    TreeNode * buildTreeHelper(vector<int> & preorder, vector<int> & inorder, int start, int end){
        if (start >= end) return NULL;
        int val = preorder[preorder.size()-1];
        int index = find(inorder, start, end, val); // O(N) in the worst case;
        if (index == -1) return NULL;
        TreeNode * root = new TreeNode(val);
        preorder.pop_back();
        root->left = buildTreeHelper(preorder,inorder,start,index);
        root->right = buildTreeHelper(preorder,inorder,index+1,end);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { //O(N^2) in the worst case
        int n = inorder.size();
        if (n == 0) return NULL;
        reverse(preorder.begin(),preorder.end()); // DOES NOT CONVERT PREORDER TO POST ORDER
        TreeNode * root = buildTreeHelper(preorder,inorder,0,n);
        return root;
    }
};
