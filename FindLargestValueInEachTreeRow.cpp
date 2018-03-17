/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//CAN BE SOLVED WITH BOTH DFS AND BFS. THIS ONE IS A DFS solution
class Solution {
    
private:
    void dfs(TreeNode * root, int level, vector<int> & answer){
        if (root == NULL) return;
        if (answer.size() < level){
            answer.push_back(root->val);
        }
        else{
            answer[level-1] = max(answer[level-1], root->val);
        }
        dfs(root->left,level+1,answer);
        dfs(root->right,level+1,answer);
        
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> answer;
        if (root == NULL) return answer;
        dfs(root, 1, answer);
        return answer;
    }
};
