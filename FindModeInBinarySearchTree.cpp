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
    void inorder(TreeNode * root, int & maxFreq, int & curFreq, TreeNode *& preNode){
        //PROCESS LEFT NODE
        if (root->left != NULL){
            inorder(root->left, maxFreq, curFreq, preNode);
        }

        //PROCESS CURRENT NODE
        if (preNode != NULL){
            if (root->val == preNode->val) curFreq++;
            else curFreq = 1;
        }
        maxFreq = max(maxFreq,curFreq);
        preNode = root;
        
        //PROCESS RIGHT NODE
        if (root->right != NULL){
            inorder(root->right, maxFreq, curFreq, preNode);
        }
        
        return;
    }
    
    void getModes(TreeNode * root, int maxFreq, int & curFreq, TreeNode *& preNode, vector<int> & result){
        //PROCESS LEFT NODE
        if (root->left != NULL){
             getModes(root->left, maxFreq, curFreq, preNode, result);
        }
        
        //PROCESS CURRENT NODE
        if (preNode != NULL){
            if (root->val == preNode->val) curFreq++;
            else curFreq = 1;
        }
        if (curFreq == maxFreq) result.push_back(root->val);
        preNode = root;
        
        //PROCESS RIGHT NODE
        if (root->right != NULL){
            getModes(root->right,maxFreq, curFreq, preNode, result);
        }
    
        return;
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        int maxFreq = 1;
        int curFreq = 1;
        TreeNode * preNode = NULL;
        vector<int> result;
        if (root == NULL) return result;
        
        inorder(root, maxFreq, curFreq, preNode);
        preNode = NULL;
        curFreq=1;
        getModes(root, maxFreq, curFreq, preNode, result);
        return result;
    }
};
