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
    int find(vector<int> & post, int val, int post_s, int post_e){
        for (int i = post_s; i <= post_e; i++){
            if (post[i] == val) return i;
        }
        return -1;
    }
    
    TreeNode * constructTreeHelper(vector<int> & pre, vector<int> & post, int post_s, int post_e){
        if (post_s > post_e) return NULL;
        if (pre.size() == 0) return NULL;
        int val = pre[pre.size()-1];
        int index = find(post, val, post_s, post_e);
        if (index == -1) return NULL;
        TreeNode * root = new TreeNode(val);
        pre.pop_back();     //this gets rid of elements from pre order
        root->left = constructTreeHelper(pre, post, post_s, index-1); 
        root->right = constructTreeHelper(pre, post, post_s, index-1); //TRY to think how nodes are arranged in post order
        return root;
    }
    
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        reverse(pre.begin(), pre.end());
        TreeNode * root = constructTreeHelper(pre, post, 0, n-1);
        return root;
    }
};
