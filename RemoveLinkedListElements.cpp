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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        while (head != NULL && head->val == val) head = head->next;
        ListNode * node = head;
        while (node != NULL && node->next != NULL){
            if ((node->next)->val == val) node->next = (node->next)->next;
            else node = node->next;
        }
        return head;
    }
};
