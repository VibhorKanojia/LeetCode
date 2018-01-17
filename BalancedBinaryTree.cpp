/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node{
    TreeNode * node;
    Node * left;
    Node * right;
    int height;
    Node(TreeNode * node, int height){
        this->node = node;
        this->height = height;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
private:
    int getHeight(Node * root){
        if (root == NULL) return 0;
        else return root->height;    
    }
    
    Node * makeTree(Node* new_root, TreeNode * root){
        if (root == NULL) return NULL;
        new_root = new Node(root,1);
        new_root->left = makeTree(new_root->left, root->left);
        new_root->right = makeTree(new_root->right, root->right);
        new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) +1;
        return new_root;
    }
    
    bool checkBalanced(Node * root){
        if (root == NULL) return true;
        if ( abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
        return (checkBalanced(root->left) && checkBalanced(root->right));
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        Node * new_root;
        new_root = makeTree(new_root, root);
        
        return checkBalanced(new_root);
        
    }
};
