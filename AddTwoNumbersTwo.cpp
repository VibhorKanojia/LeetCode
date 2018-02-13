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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1;
        stack<int> num2;
        while (l1 != NULL){
            num1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL){
            num2.push(l2->val);
            l2 = l2->next;
        }
        ListNode * head = NULL;
        int carry = 0;
        while(!num1.empty() && !num2.empty()){
            int d1 = num1.top();
            num1.pop();
            int d2 = num2.top();
            num2.pop();
            int sum = d1+d2+carry;
            ListNode * temp = new ListNode(sum%10);
            temp->next = head;
            head = temp;
            carry = sum/10;
        }
        
        while (!num1.empty()){
            int d1 = num1.top();
            num1.pop();
            int sum = d1 + carry;
            ListNode * temp = new ListNode(sum%10);
            temp->next = head;
            head = temp;
            carry = sum/10;
        }
        
        while (!num2.empty()){
            int d1 = num2.top();
            num2.pop();
            int sum = d1 + carry;
            ListNode * temp = new ListNode(sum%10);
            temp->next = head;
            head = temp;
            carry = sum/10;
        }
        
        if (carry != 0){
            ListNode * temp = new ListNode(carry);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};
