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
    bool isLeaf(TreeNode * node){
        if (node->left == NULL) return (node->right == NULL);
        else return false;
    }
    
    void backtrack(TreeNode* root, string path, vector<string> & answer){
        if (root == NULL) return;
        
        if (isLeaf(root)){
            path = path + to_string(root->val);
            answer.push_back(path);
            return;
        }
        path = path + to_string(root->val) + "->";
        
        backtrack(root->left,path,answer);
        backtrack(root->right,path,answer);
        path = path.substr(0, path.size()-2);
        return;
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        if (root == NULL) return answer;
        string path ="";
        backtrack(root, path, answer);
        return answer;
    }
};
