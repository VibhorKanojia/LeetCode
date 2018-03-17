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
    bool isEqual(TreeNode * s, TreeNode * t){
        if (s == NULL) return (t == NULL);
        else if (s != NULL){
            if (t == NULL) return false;
            if (s->val != t->val) return false;
            else return (isEqual(s->left, t->left) && isEqual(s->right,t->right));
        }
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) return (t == NULL);
        if (isEqual(s,t)) return true;
        else{
            return (isSubtree(s->left,t) || isSubtree(s->right,t));
        }   
    }
};
