/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode * cur_node = head;
        while (cur_node != NULL && cur_node->next != NULL){
            ListNode * next_node = cur_node->next;
            if (cur_node->val == next_node->val) cur_node->next = next_node->next;
            else cur_node = cur_node->next;
        }
        
        return head;
    }
};
