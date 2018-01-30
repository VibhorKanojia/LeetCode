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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        stack<ListNode *> buffer;
        int length = 0;
        ListNode * cur_node = head;
        while (cur_node != NULL){
            length++;
            buffer.push(cur_node);
            cur_node = cur_node->next;
        }
        
        while( k != 0 && k % length != 0){
            cur_node = buffer.top();
            buffer.pop();
            cur_node->next = head;
            head = cur_node;
            k--;
        }
        cur_node = buffer.top();
        cur_node->next = NULL;
        return head;
    }
};
