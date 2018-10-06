/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void preorder(TreeNode * root, string & res){
        if (root == NULL) return;
        res = res + to_string(root->val) + "#";
        preorder(root->left, res);
        preorder(root->right, res);
        return;
    }
    
    void inorder(TreeNode * root, string & res){
        if (root == NULL) return;
        inorder(root->left, res);
        res = res + to_string(root->val) + "#";
        inorder(root->right, res);
        return;
    }
    
    void fill_array(string & data, vector<int> & array){
        string num = "";
        int i = 0;
        for (i = 0 ; i < data.size(); i++){
            if ((data[i] >= '0' && data[i] <= '9') || data[i] == '-'){
                num = num + data[i];
            }
            else if (data[i] == '#'){
                array.push_back(atoi(num.c_str()));
                num = "";
            }
            else if (data[i] == '&'){
                data = data.substr(i+1);
                break;
            }
        }
        return;
    }
    
    int find(vector<int> & in_vec, int val, int start, int end){
        for (int i = start; i <= end; i++){
            if (in_vec[i] == val) return i;
        }
        return -1;
    }
    
    TreeNode * createBT(vector<int> & pre_vec, vector<int> & in_vec, int start, int end){
        if (start > end) return NULL;
        if (pre_vec.empty()) return NULL;
        int val = pre_vec[pre_vec.size()-1];
        int index = find(in_vec, val, start, end);
        if (index == -1) return NULL;
        TreeNode * root = new TreeNode(val);
        pre_vec.pop_back();
        root->left = createBT(pre_vec, in_vec, start, index-1);
        root->right = createBT(pre_vec, in_vec, index+1, end);
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        preorder(root, result);
        result = result + "&";
        inorder(root, result);
        cout<<result<<endl;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> pre_vec;
        vector<int> in_vec;
        fill_array(data, pre_vec);
        fill_array(data, in_vec);
        
        reverse(pre_vec.begin(), pre_vec.end());
        TreeNode * root = createBT(pre_vec, in_vec, 0, in_vec.size()-1);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
