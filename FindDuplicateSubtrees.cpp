//Must Do Question
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
    string postOrder(TreeNode * root, vector<TreeNode *> & result, unordered_map<string,int> & mapper){
        if (root == NULL) return "#";
        string hasher = postOrder(root->left, result, mapper) + postOrder(root->right, result, mapper) + to_string(root->val);
        auto it = mapper.find(hasher);
        if (it == mapper.end()) mapper.insert(pair<string,int>(hasher,1));
        else {
            if (it->second == 1) {
                result.push_back(root);
            }
            it->second++;
        }
        return hasher;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> result;
        if (root == NULL) return result;
        unordered_map<string,int> mapper;
        postOrder(root, result, mapper);
        return result;
    }
};
