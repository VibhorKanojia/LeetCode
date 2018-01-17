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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode * ptr1 = head;
        ListNode * ptr2 = head;
        
        do{
            ptr1 = ptr1->next;
            ptr2 = (ptr2->next);
            if (ptr2 != NULL) ptr2 = ptr2->next;
            if (ptr1 == NULL || ptr2 == NULL) return false;
        }while (ptr1 != ptr2);
        
        return true;
    }
};
