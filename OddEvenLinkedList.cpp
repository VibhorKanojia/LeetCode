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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode * oddptr = head;
        ListNode * evenptr = head->next;
        ListNode * evenhead = evenptr;
        while (evenptr != NULL && evenptr->next != NULL){
            ListNode * nxtodd = evenptr->next;
            ListNode * nxteven = nxtodd->next;
            oddptr->next = nxtodd;
            oddptr = nxtodd;
            nxtodd->next = evenhead;
            evenptr->next = nxteven;
            evenptr = nxteven;
        }
        return head;
    }
};
