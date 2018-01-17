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
    //reverses the nodes AFTER the head node;
    ListNode * reverse(ListNode * head){
        if (head == NULL || head->next == NULL) return NULL;
        ListNode * node1= head;
        ListNode * cur_head = node1;
        while(node1->next != NULL){
            ListNode * node2 = node1->next;
            ListNode * node3 = node2->next; //can be null;
            node2->next=cur_head;
            cur_head = node2;
            node1->next = node3;
        }
        return cur_head;
    }
    
    ListNode * getCenter(ListNode * head){
        if (head == NULL) return NULL;
        ListNode * center = NULL;
        ListNode * ptr1 = head;
        ListNode * ptr2 = head;
        while(ptr2 != NULL && ptr2->next != NULL){
            center = ptr1;
            ptr1 = ptr1->next;
            ptr2 = (ptr2->next)->next;
        }
        return center;
    }
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || (head->next)->next == NULL) return;
        ListNode * center = getCenter(head);
        cout<<center->val<<endl;
        center->next = reverse(center->next);
        ListNode * ptr1 = head;
        ListNode * ptr2 = center->next;
        while (ptr1 != center && ptr2 != NULL){
            ListNode * temp1 = ptr1->next;
            ListNode * temp2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = temp1;
            ///temp1->next = temp2;
            ptr1 = temp1;
            ptr2 = temp2;
            
        }
        ptr1->next = ptr2;
        return;
    }
};
