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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int position = 1;
        ListNode * par_node = NULL;
        ListNode * cur_node = head;
        
        while (position != m){
            par_node = cur_node;
            cur_node = cur_node->next;
            position++;
        }
        ListNode * cur_head = cur_node;
        while (position != n && cur_node->next != NULL){
            ListNode * next_node = cur_node->next;
            ListNode * new_next = next_node->next;
            next_node->next = cur_head;
            cur_head = next_node;
            cur_node->next = new_next;
            position++;
        }
        if (par_node == NULL) return cur_head;
        else {
            par_node->next = cur_head;
            return head;
        }
        
    }
};
