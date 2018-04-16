/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode * sortedBST(vector<int> & array, int start, int end){
        if (start > end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode * root = new TreeNode(array[mid]);
        root->left = sortedBST(array,start,mid-1);
        root->right = sortedBST(array,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> array;
        while (head != NULL){
            array.push_back(head->val);
            head = head->next;
        }
        
        return sortedBST(array,0,array.size()-1);
    }
};
