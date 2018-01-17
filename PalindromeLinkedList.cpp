/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode * head){
        int count = 0;
        while (head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode * reverse(ListNode * head, int K){
        ListNode * new_head = head;
        ListNode * cur_node = head;
        int count = 1;
        while (count < K){
            ListNode * next_node = cur_node->next;
            ListNode * temp = next_node->next;
            cur_node->next = temp;
            next_node->next = new_head;
            new_head = next_node;
            count++;
        }
        return new_head;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next ==  NULL) return true;
        int length = getLength(head);
        head = reverse(head,length/2);
        
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        for (int i = 0 ; i < length/2; i++) ptr2 = ptr2->next;
        
        if (length%2 != 0) ptr2= ptr2->next;
        while (ptr2 != NULL){
            if (ptr1->val != ptr2->val) return false;
            ptr1= ptr1->next;
            ptr2=ptr2->next;
        }
        return true;
    }
};
