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
        ListNode * par_node = NULL;
        ListNode * cur_node = head;
        bool dupFlag = 0;
        while (cur_node != NULL && cur_node->next != NULL){
            ListNode * next_node = cur_node->next;
            if (cur_node->val  == next_node->val){
                cur_node->next = next_node->next;
                dupFlag = 1;
            }
            else{
                if (dupFlag == 1){
                    if (cur_node == head){
                        dupFlag = 0;
                        cur_node = cur_node->next;
                        head = cur_node;
                    }
                    else{
                        dupFlag = 0;
                        cur_node = cur_node->next;
                        par_node->next = cur_node;
                    }
                }
                else{
                    par_node = cur_node;
                    cur_node = cur_node->next;
                }
            }
        }
        
        if (dupFlag == 1){
            if (cur_node == head){
                return NULL;
            }
            else{
                par_node->next = NULL;
            }
        }
        
        return head;
    }
};
