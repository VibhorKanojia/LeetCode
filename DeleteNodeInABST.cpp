//SOLUTION ONE. MORE INTUITIVE BUT RUNTIME IS 38ms
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val == key){
            if (root->left == NULL) return root->right;
            else if (root->right == NULL) return root->left;
            else{
                TreeNode * temp = root->left;
                while (temp->right != NULL) temp = temp->right;
                root->val = temp->val;
                root->left = deleteNode(root->left,temp->val);
            }
        }
        else if (root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        
        return root;
    }
};

//SOLUTION TWO. REALLY COMPLICATED BUT RUNTIME IS 36ms
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
    TreeNode * findParent(TreeNode * root, int key, TreeNode * parent){
        if (root == NULL || root->val == key) return parent;
        if (root->val > key) return findParent(root->left, key, root);
        else return findParent(root->right,key, root);
    }
    
    TreeNode * deleteRoot(TreeNode * root){
        if (root->left == NULL) return root->right;
        else if (root->right == NULL) return root->left;
        else{
            TreeNode * temp = root->left;
            while (temp->right != NULL) temp = temp->right;
            int val = temp->val;
            root = deleteNode(root, temp->val);
            root->val = val;
        }
        return root;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        TreeNode * parent = NULL;
        parent = findParent(root, key, NULL);
        TreeNode * node = NULL;
        if (parent == NULL) {
            return deleteRoot(root);
        }
        else if (parent->left != NULL && parent->left->val == key){
            parent->left= deleteRoot(parent->left);
        }
        
        else if (parent->right != NULL && parent->right->val == key){
            parent->right = deleteRoot(parent->right);
        }
        
        return root;  
    }
};
