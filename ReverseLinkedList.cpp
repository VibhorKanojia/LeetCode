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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL  || head->next == NULL) return head;
        ListNode * new_head = head;
        ListNode * node = head;
        
        while (node->next != NULL){
            ListNode * next_node = node->next;
            ListNode * new_next = next_node->next;
            next_node->next = new_head;
            new_head = next_node;
            node->next = new_next;
        }
        
        return new_head;
    }
};
