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
    int postOrder(TreeNode * root, unordered_map<int,int> & mapper, int & max_freq){
        if (root == NULL) return 0;
        int cur_val = 0;
        cur_val += postOrder(root->left, mapper, max_freq);
        cur_val += postOrder(root->right, mapper, max_freq);
        cur_val += root->val;
        auto it = mapper.find(cur_val);
        if (it == mapper.end()){
            mapper[cur_val] = 1;
        }
        else{
            mapper[cur_val]++;
        }
        max_freq = max(max_freq, mapper[cur_val]);
        return cur_val;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        unordered_map<int, int> mapper;
        int max_freq = -1;
        postOrder(root, mapper, max_freq);
        for (auto it = mapper.begin(); it != mapper.end(); it++){
            if (it->second == max_freq) result.push_back(it->first);
        }
        return result;
    }
};/**
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
    int postOrder(TreeNode * root, unordered_map<int,int> & mapper, int & max_freq){
        if (root == NULL) return 0;
        int cur_val = 0;
        cur_val += postOrder(root->left, mapper, max_freq);
        cur_val += postOrder(root->right, mapper, max_freq);
        cur_val += root->val;
        auto it = mapper.find(cur_val);
        if (it == mapper.end()){
            mapper[cur_val] = 1;
        }
        else{
            mapper[cur_val]++;
        }
        max_freq = max(max_freq, mapper[cur_val]);
        return cur_val;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        unordered_map<int, int> mapper;
        int max_freq = -1;
        postOrder(root, mapper, max_freq);
        for (auto it = mapper.begin(); it != mapper.end(); it++){
            if (it->second == max_freq) result.push_back(it->first);
        }
        return result;
    }
};
