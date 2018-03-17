/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Data{
    TreeNode * node;
    int width;
    Data(TreeNode *node, int width){
        this->node = node;
        this->width = width;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<Data *> buffer;
        Data * src = new Data(root, 1);
        int count = 1;
        int max_width = INT_MIN;
        int level_min = INT_MAX;
        int level_max = INT_MIN;
        buffer.push(src);
        
        while(!buffer.empty()){
            Data * cur = buffer.front();
            buffer.pop();
            level_min = min(level_min,cur->width);
            level_max = max(level_max,cur->width);
            count--;
            if ((cur->node)->left != NULL){
                Data * temp = new Data((cur->node)->left, (cur->width)*2-1); 
                buffer.push(temp);
            }
            if ((cur->node)->right != NULL){
                Data * temp = new Data((cur->node)->right, (cur->width)*2); 
                buffer.push(temp);
            }
            if (count == 0){
                max_width = max(max_width, level_max-level_min+1);
                level_min = INT_MAX;
                level_max = INT_MIN;
                count = buffer.size();
            }
        }
        return max_width;
    }
};
