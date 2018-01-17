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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> solution;
        if (root == NULL) return solution;
        
        int level = 0; 
        queue<TreeNode *> buffer;
        buffer.push(root);
        int count = 1;
        while(!buffer.empty()){
            TreeNode * elem = buffer.front();
            buffer.pop();
            while (solution.size() <= level){
                vector<int> temp;
                solution.push_back(temp);
            }
            solution[level].push_back(elem->val);
            count--;
            
            if (elem->left != NULL){
                buffer.push(elem->left);
            }
            if (elem->right != NULL){
                buffer.push(elem->right);
            }
            
            if (count == 0) {
                level++;
                count = buffer.size();
            }
        }
        for (int i = 1 ; i < solution.size(); i +=2){
            reverse(solution[i].begin(),solution[i].end());
        }
        return solution;
        
    }
};
